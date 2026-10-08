[English version](README.en.md)

# Nadzornik mikroklime v kovčku za violino

Vgrajen sistem za neprekinjeno spremljanje relativne vlažnosti in temperature znotraj kovčka za godala. Projekt rešuje problem poškodb laka in lesa zaradi suhega zraka (pod 40 % RH) ter hitrih temperaturno-vlažnostnih nihanj ob prehodih med prostori. 

Razvoj poteka v dveh ločenih fazah v jeziku C++:
1. **1. polletje (Arduino Uno):** Samostojna naprava z lokalnim I2C zaslonom, zaznavanjem odprtja kovčka ter beleženjem ekstremov brez zunanjih povezav.
2. **2. polletje (ESP32):** Prehod na boljšo platformo z uporabo `deep-sleep` ciklov, BLE (GATT) telemetrijo in integracijo z namensko Android aplikacijo (*Jetpack Compose* / *Material 3 Expressive*).

---

## Glavne načrtovane funkcionalnosti

* **Merjenje ključnih parametrov:** Branje relativne vlažnosti in temperature preko digitalnega I2C vodila (SHT31 / prototipno DHT11).
* **Nadzor hitrosti spremembe:** Opozorilo ob nenadnih padcih vlažnosti v kratkih časovnih oknih, ne zgolj ob statičnih mejah.
* **Črna skrinjica (Flight Recorder):** Beleženje minimalnih/maksimalnih vrednosti in skupnega časa izpostavljenosti nevarnim pogojem med zaprtim kovčkom.
* **Zaznava stanja pokrova:** Z uporabo magnetnega stikala (reed switch) sistem ob zaprtem kovčku ugasne zaslon zaradi varčevanja, ob odprtju pa prikaže povzetek stanja.
* **Zvočno in vizualno opozorilo:** Piezo brenčač in statusna LED za kritična odstopanja.

---

## Strojna oprema

| Komponenta | Model / Opis | Protokol / Povezava |
| :--- | :--- | :--- |
| **Krmilnik (Faza 1)** | Arduino Uno R3 (ATmega328P) | — |
| **Krmilnik (Faza 2)** | ESP32 / ESP32-C3 SuperMini | BLE / Wi-Fi |
| **Senzor vlage in temp.** | SHT31-D (prototip: DHT11) | I2C (0x44) |
| **Zaslon** | 0.96" SSD1306 OLED (ali 1602 LCD) | I2C (0x3C) |
| **Senzor odprtja** | Reed stikalo + magnet | Digitalni vhod (Pull-up) |
| **Indikatorji** | Piezo brenčač + dvobarvna LED | PWM / Digitalni izhod |

---

## Struktura programske opreme

Struktura še ni predvidena.

```text
├── src/
│   ├── main.cpp              # Glavna zanka 
├── docs/                     
└── README.md
```

---

## Namestitev in zagon

1. Odpri projekt v **PlatformIO** (ali Arduino IDE).
2. Namesti potrebne `adafruit` knjižnice za I2C zaslon in senzor.
3. Preveri povezavo I2C vodila na ustreznih pinih.
4. Naloži kodo na krmilnik prek USB kabla.
