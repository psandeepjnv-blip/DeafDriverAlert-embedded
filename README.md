# Deaf Driver Alert System

An embedded system designed to assist hearing-impaired drivers by detecting nearby obstacles and translating distance information into a clear, tiered visual alert — using an 8051 microcontroller, an analog distance-equivalent input stage, an LCD readout, and dual-LED proximity warnings.

## Overview

Deaf drivers cannot rely on auditory cues (horns, sirens, proximity beeps) that most vehicle safety systems assume are available. This project demonstrates a fully visual alert pipeline: a variable analog input representing real-world distance is sampled, converted, and processed by an AT89C51 microcontroller, which displays the live distance value on an LCD and drives two LEDs into three distinct alert states.

## System Architecture

1. **Analog Input:** Potentiometer simulates distance voltage.
2. **ADC0808:** Converts analog voltage to 8-bit digital data.
3. **AT89C51:** Microcontroller processes thresholds and drives outputs.
4. **LCD & LEDs:** Visual feedback via live distance display and tiered LED alerts.

![Circuit Schematic](Images/circuit-diagram.png)

## Components Used

| Component | Role |
|---|---|
| AT89C51 | Core microcontroller, runs threshold decision logic |
| ADC0808 | Converts analog voltage to an 8-bit digital value |
| Potentiometer (1k) | Simulates variable distance input |
| LM016L LCD | Displays live distance/value reading |
| LED (Red) | Danger zone indicator |
| LED (Yellow) | Warning zone indicator |
| DCLOCK Generator | Provides required clock signal to ADC0808 |

## Alert Logic

| Reading Range | Red LED | Yellow LED | Meaning |
|---|---|---|---|
| Below ~65 | ON | OFF | Danger — object very close |
| ~65 to ~160 | OFF | ON | Warning — object approaching |
| Above ~160 | OFF | OFF | Safe — no nearby obstruction |

## Engineering Log: Key Debugging Milestones

- **Sensor Simulation:** Identified Echo pulse timing failures in simulation.
- **Clock Integration:** Implemented a DCLOCK generator at 500kHz to enable ADC conversion.
- **Output Enable (OE):** Wired OE permanently HIGH to ensure the 8-bit bus remains active.
- **Active-LOW LEDs:** Inverted firmware logic to match the hardware pull-up configuration.

## Author

Developed and debugged by **[Your Name]**.
