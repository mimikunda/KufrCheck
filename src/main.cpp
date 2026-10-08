#include <Arduino.h>
#include <DHT.h>

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

void setup() {
  Serial.begin(9600);
  dht.begin();
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
}