# Guardian Sense: A Smart Fall Detector with User Confirmation

[![Status](https://img.shields.io/badge/status-hackathon_prototype-brightgreen)](https://github.com/) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

An intelligent, wearable fall detection system designed to eliminate false alarms through a smart user-confirmation feature. Built for the modern caregiver and independent senior.

[![Watch the video](https://img.youtube.com/vi/EzCF61Dqsik/0.jpg)](https://www.youtube.com/watch?v=EzCF61Dqsik)

---

## Problem Statement

Standard fall detectors suffer from a "cry-wolf" problem. They frequently trigger false alarms from accidental drops or sudden movements, causing unnecessary panic for users and desensitizing caregivers to real emergencies. This erodes trust and makes the safety net unreliable.

Our solution, **Guardian Sense**, tackles this head-on by adding a layer of intelligence to confirm a fall before ever sending an alert.

---

## Key Features ✨

* **Two-Stage Alert System:** A primary tilt sensor triggers a soft, local confirmation alert instead of an immediate emergency broadcast.
* **User Cancellation:** A 15-second on-device countdown (shown on an LCD screen) allows the user to cancel a false alarm with a single button press.
* **Automatic Escalation:** If the user is unresponsive and does not cancel, the system automatically escalates to a full emergency alert.
* **Multi-Modal Alerts:** The full alert consists of a loud, flashing red light from an RGB LED and an instant notification sent via **Telegram Bot API** to a caregiver's phone.
* **Reliable & Contained:** The entire system runs on a single, low-power Seeed Studio XIAO ESP32-S3 board.

---

## Tech Stack & Hardware 🛠️

This is a hardware-focused IoT project built with accessible, off-the-shelf components.

#### Hardware
* **Microcontroller:** Seeed Studio XIAO ESP32-S3
* **Primary Sensor:** SW-520D Tilt Sensor
* **User Interface:** I2C LCD1602 Display
* **Alerts:** KY-016 RGB LED Module & Active Buzzer
* **Input:** Tactile Push-Button Switch

#### Software & Cloud
* **Firmware:** C++ on the Arduino Framework
* **Connectivity:** Onboard Wi-Fi
* **Notification Service:** Telegram Bot API

---

## Hardware Connections 🔌

| Component           | Connection on XIAO ESP32-S3                       |
| ------------------- | ------------------------------------------------- |
| **I2C LCD Display** | `SDA`→`D5`, `SCL`→`D6`, `VCC`→`5V`, `GND`→`GND`      |
| **Tilt Sensor** | One leg → `D7`, Other leg → `GND`                   |
| **Buzzer** | `+` → `D2`, `-` → `GND`                             |
| **RGB LED** | `R`→`D4`, `G`→`D8`, `B`→`D9`, `-`(Anode)→`3V3`       |
| **Tactile Switch** | One leg → `D10`, Other leg → `GND`                  |

---

## Getting Started

### Prerequisites

1.  **Hardware:** You'll need all the components listed above.
2.  **Software:**
    * [Arduino IDE](https://www.arduino.cc/en/software)
    * ESP32 Board Support Package for Arduino IDE.
3.  **Arduino Libraries:**
    * `LiquidCrystal_I2C` by Frank de Brabander
    * `UniversalTelegramBot` by Brian Lough

### Setup & Installation

1.  **Clone the Repository:**
    ```bash
    git clone https://github.com/dearabhin/Guardian-Sense.git
    ```
2.  **Assemble the Hardware:** Connect all the components to the XIAO ESP32-S3 as per the connection table above.
3.  **Configure Credentials:** Open the main `.ino` sketch and update the following credentials:
    ```cpp
    // ---- WI-FI & TELEGRAM CREDENTIALS ----
    const char* ssid     = "YOUR_WIFI_SSID";
    const char* password = "YOUR_WIFI_PASSWORD";
    #define BOT_TOKEN "YOUR_TELEGRAM_BOT_TOKEN"
    #define CHAT_ID "YOUR_TELEGRAM_CHAT_ID"
    ```
4.  **Upload the Code:**
    * Select "Seeed Studio XIAO ESP32-S3" as your board in the Arduino IDE.
    * Select the correct COM port.
    * Upload the sketch.

---

## Goals 🚀

* **Sensor Fusion:** Upgrade the tilt sensor to an IMU (e.g., MPU6050) to implement more sophisticated fall detection algorithms based on acceleration and orientation data.
* **AI Verification:** Implement our planned two-device system where a stationary AI camera visually confirms the fall, providing a fully automatic verification layer.
* **Miniaturization:** Design a custom PCB to create a smaller, more commercially viable product with improved battery life.