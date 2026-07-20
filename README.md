# Interactive Gun Shooting System

## Project Description

The Interactive Gun Shooting System is an interactive gaming setup that allows users to play a shooting game using a physical toy gun connected with an electronic control system. The system combines hardware integration, motion tracking, and software communication to create a real-time shooting experience.

During gameplay, a video-based target environment is displayed on a screen. The user aims the toy gun toward the screen, and the system tracks the gun position to control the aiming pointer. When the trigger is pressed, the system detects the input and sends the command to the game application, allowing the user to hit targets and calculate scores.

This project demonstrates the integration of embedded systems, servo-based motion tracking, communication interfaces, and interactive application control.

---

## Working Principle

1. The game application starts and displays the shooting environment on the screen.
2. The user aims the toy gun toward different positions on the screen.
3. Servo motors are used for X and Y axis movement calculation to track the gun position.
4. The position values are read through the TTLinker interface and processed by the ESP32 controller.
5. ESP32 communicates the position data to the computer application.
6. When the user presses the trigger, the trigger switch sends an input signal to the ESP32.
7. The ESP32 sends the trigger command to the application.
8. The application processes the hit position and updates the score.

---

## Features

- Real-time interactive shooting gameplay
- Physical toy gun interface
- X-Y axis position tracking
- Servo-based motion control
- Trigger detection system
- ESP32-based embedded controller
- Communication between hardware and PC application
- Real-time score calculation
- Video-based gaming environment

---

## Hardware Components

- ESP32 Development Board
- Toy Gun Setup
- Servo Motors (X and Y axis movement tracking)
- TTLinker Communication Module
- Trigger Switch
- Power Supply
- Connecting Wires and Electronics Components

---

## Software & Technologies

- Embedded C/C++
- ESP32 Firmware Development
- Serial Communication
- PC Application Interface
- Real-time Data Processing

---

## System Architecture
