# Ultrasonic Distance Sensor with Dynamic LED Warning System

## Overview
This project uses an **ultrasonic distance sensor** to measure the distance of nearby objects and **lights up different LEDs** (green, yellow, or red) depending on how close the object is. The **distance threshold** can be **adjusted in real-time** using a **potentiometer**.

It serves as a basic distance-based warning system suitable for robotics, parking assistance, or safety alert systems.

## Components Used
- Ultrasonic Sensor (HC-SR04 or similar)
- Arduino-compatible microcontroller
- 3 LEDs (Green, Yellow, Red)
- 3 Resistors (220Ω recommended for each LED)
- Potentiometer
- Breadboard and jumper wires

## Pin Connections
| Component                | Arduino Pin |
|---------------------------|-------------|
| Ultrasonic Trig Pin       | D6          |
| Ultrasonic Echo Pin       | D5          |
| Green LED                 | D10         |
| Yellow LED                | D9          |
| Red LED                   | D8          |
| Potentiometer (Middle Pin)| A0          |

## How It Works
1. The Arduino sends a pulse from the **Trig** pin of the ultrasonic sensor.
2. It measures the time taken for the pulse to return via the **Echo** pin.
3. The time is converted into a **distance** in centimeters.
4. The **potentiometer** adjusts the maximum distance threshold.
5. Based on the distance:
   - **Red LED** lights up if distance < 1/3 of threshold.
   - **Yellow LED** lights up if distance is between 1/3 and 2/3 of threshold.
   - **Green LED** lights up if distance > 2/3 of threshold.
6. Distance and threshold values are printed to the **Serial Monitor** at 9600 baud.

## Code Summary
- **Pin Setup**: Configures pins for sensor, LEDs, and potentiometer.
- **Distance Calculation**: Uses pulse duration to compute distance.
- **Threshold Adjustment**: Reads analog input from the potentiometer.
- **LED Control**: Lights up one LED depending on proximity.
- **Serial Output**: Provides live feedback for easier testing.

## Notes
- Adjust the potentiometer to fine-tune system sensitivity without reprogramming.
- Always use resistors with LEDs to avoid burning them out.
- The formula `distance = duration * 0.034 / 2` assumes the speed of sound is ~343 m/s at room temperature.

## Future Improvements
- Add a buzzer to provide sound warnings based on distance.
- Display the distance on an LCD or OLED screen.
- Create a calibration mode for easier initial setup.

---

> **Reminder**: Always double-check your wiring before powering the system to prevent any short circuits.


