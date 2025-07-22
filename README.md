# IoT Based Real-Time Methane Monitoring System for Landfills
A project that demonstrates a low-cost, IoT based environmental monitoring system along with ThingSpeak data visualisation platform.

## Overview

This system is built to address the growing concern of gas accumulation in landfill sites, which can pose serious health and environmental hazards. Using a combination of calibrated gas sensors — MQ-4 for methane, MQ-135 for carbon dioxide and other harmful gases, and DHT11 for temperature and humidity — the system captures real-time data and transmits it to the cloud via Wi-Fi.
The data is visualized on **ThingSpeak**, allowing continuous monitoring and analysis. An **OLED display** provides instant local readings, while a web interface issues **smart alerts** to nearby personnel, improving safety and decision-making. Future extensions include scaling the system for wide-area coverage and exploring methane decomposition techniques for energy recovery.

## Features

- **Real-Time Monitoring**: Tracks methane (CH₄), carbon dioxide (CO₂), temperature, and humidity in landfill environments.
- **Cloud Connectivity**: Uploads sensor data to ThingSpeak for live graphing and analytics.
- **OLED Display**: Displays gas concentration locally for on-site monitoring.
- **Smart Alerts**: Sends web-based notifications when critical levels are detected.
- **Sustainability Focus**: Aims to convert harmful methane into safe compounds or useful energy in future phases.

## Hardware Components  
The following list has been sourced from the project report.

| S.No | Component                                | Quantity |
|------|------------------------------------------|----------|
| 1    | MQ-4 Gas Sensor (Methane)                | 1        |
| 2    | MQ-135 Gas Sensor (CO₂ and other gases)  | 1        |
| 3    | DHT11 Sensor (Temperature & Humidity)    | 1        |
| 4    | ESP32 / NodeMCU (Wi-Fi Microcontroller)  | 1        |
| 5    | OLED Display (I2C 128x64)                | 1        |
| 6    | 5V DC Power Supply                       | 1        |
| 7    | Custom PCB                               | 1        |
| 8    | Wi-Fi Access Point                       | 1        |
| 9    | ThingSpeak-compatible Web Dashboard      | 1        |


## 👨‍💻 Author

**Akshay Kumar A.** 

