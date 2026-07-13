\# Deaf Driver Alert System



An embedded system designed to assist hearing-impaired drivers by detecting nearby obstacles and translating distance information into a clear, tiered visual alert — using an 8051 microcontroller, an analog distance-equivalent input stage, an LCD readout, and dual-LED proximity warnings.



\## Overview



Deaf drivers cannot rely on auditory cues (horns, sirens, proximity beeps) that most vehicle safety systems assume are available. This project demonstrates a fully visual alert pipeline: a variable analog input representing real-world distance is sampled, converted, and processed by an AT89C51 microcontroller, which displays the live distance value on an LCD and drives two LEDs into three distinct alert states — Danger (Red), Warning (Yellow), and Safe (both off).



The system was originally designed around an HC-SR04/SRF04 ultrasonic distance sensor. During simulation in Proteus 8 Professional, both sensor models exhibited non-functional Echo pulse timing that could not be resolved despite exhaustive diagnostics (documented below). The analog input stage was substituted with a potentiometer-driven ADC0808, preserving the complete decision-logic and alert pipeline exactly as designed. In physical hardware deployment, the HC-SR04 sensor would replace this input stage directly, with no change required to the microcontroller logic.



\## System Architecture



```mermaid

flowchart LR

&#x20;   A\[Analog Distance Input<br/>Potentiometer / HC-SR04] --> B\[ADC0808<br/>8-bit Conversion]

&#x20;   B --> C\[AT89C51<br/>Microcontroller]

&#x20;   C --> D\[LM016L LCD<br/>Live Distance Readout]

&#x20;   C --> E\[Red LED<br/>Danger Zone]

&#x20;   C --> F\[Yellow LED<br/>Warning Zone]

!\[Circuit Schematic](Images/circuit-diagram.png)



