[Slovenska različica](README.md)

# Violin Case Microclimate Monitor

An embedded system for continuous monitoring of relative humidity and temperature inside a stringed instrument case. This project addresses varnish and tonewood degradation caused by dry air (below 40% RH) and rapid thermo-hygrometric shifts during environmental transitions.

Development is divided into two distinct phases in C++:

1. **Semester 1 (Arduino Uno):** Standalone device featuring a local I2C display, case lid-open detection, and local extreme-event logging without external connectivity.
2. **Semester 2 (ESP32):** Migration to an upgraded platform leveraging `deep-sleep` cycles, BLE (GATT) telemetry, and integration with a dedicated Android application (*Jetpack Compose* / *Material 3 Expressive*).

---

## Key Planned Features

* **Core Parameter Measurement:** Relative humidity and temperature acquisition via the digital I2C bus (SHT31 / prototype: DHT11).
* **Rate-of-Change Monitoring:** Alerts triggered by rapid humidity drops within tight time windows, rather than relying solely on static thresholds.
* **Flight Recorder:** Logging minimum/maximum historical values and total duration of exposure to hazardous conditions while the case remains closed.
* **Lid-State Detection:** Reed switch implementation to shut down the display when closed to conserve power, immediately rendering an environmental summary upon opening.
* **Acoustic & Visual Indicators:** Piezo buzzer and status LED for critical threshold excursions.

---

## Hardware Specifications

| Component | Model / Description | Protocol / Interface |
| --- | --- | --- |
| **MCU (Phase 1)** | Arduino Uno R3 (ATmega328P) | — |
| **MCU (Phase 2)** | ESP32 / ESP32-C3 SuperMini | BLE / Wi-Fi |
| **Temp & Humidity Sensor** | SHT31-D (prototype: DHT11) | I2C (0x44) |
| **Display** | 0.96" SSD1306 OLED (or 1602 LCD) | I2C (0x3C) |
| **Lid Sensor** | Reed switch + magnet | Digital Input (Pull-up) |
| **Indicators** | Piezo buzzer + bi-color LED | PWM / Digital Output |

---

## Software Architecture

Architecture structure is preliminary.

```text
├── src/
│   ├── main.cpp              # Main loop / Entrypoint
├── docs/                     
└── README.md

```

---

## Setup & Deployment

1. Open the project in **PlatformIO** (or Arduino IDE).
2. Install required `Adafruit` libraries for the I2C display and sensor.
3. Verify I2C bus pinout and bus addresses.
4. Flash the firmware to the microcontroller via USB.
