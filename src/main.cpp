#include <Arduino.h>
#include <DHT.h>
#include <LiquidCrystal.h>

DHT dht(2, DHT11);

struct Reading {
  unsigned long timeMs;
  float temperature;
  float humidity;
};

const int HISTORY_SIZE = 20;
Reading history[HISTORY_SIZE];
int nextIndex = 0;
int sampleCount = 0;
const int rs = 12, en = 11, d4 = 6, d5 = 5, d6 = 4, d7 = 3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("test");
}

void loop() {
  delay(2000);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Nekaj je slo narobe!");
    return;
  }

  float temperatureDifference = 0.0f;
  float humidityDifference = 0.0f;
  bool hasPrevious = (sampleCount > 0);

  if (hasPrevious) {
    int prevIndex = (nextIndex - 1 + HISTORY_SIZE) % HISTORY_SIZE;
    temperatureDifference = temperature - history[prevIndex].temperature;
    humidityDifference = humidity - history[prevIndex].humidity;
  }

  history[nextIndex] = {millis(), temperature, humidity};
  nextIndex = (nextIndex + 1) % HISTORY_SIZE;
  if (sampleCount < HISTORY_SIZE) {
    sampleCount++;
  }

  Serial.print("Temperatura: ");
  Serial.print(temperature, 1);
  Serial.print(" °C (");
  if (hasPrevious) {
    if (temperatureDifference > 0) Serial.print("+");
    Serial.print(temperatureDifference, 1);
  } else {
    Serial.print("N/A");
  }
  Serial.print("), Vlaznost: ");
  Serial.print(humidity, 1);
  Serial.print(" % (");
  if (hasPrevious) {
    if (humidityDifference > 0) Serial.print("+");
    Serial.print(humidityDifference, 1);
  } else {
    Serial.print("N/A");
  }
  Serial.println(")");
  lcd.setCursor(0,0);
  lcd.print(temperature);
  lcd.setCursor(0,1);
  lcd.print(humidity);
}