# Interactive Gun Shooting System

## Project Description
The Interactive Gun Shooting System is an interactive gaming setup developed using embedded electronics and a computer-based application to create a real-time shooting experience.
This system allows users to play a shooting game using a physical toy gun integrated with an embedded control system. When the game starts, a video-based shooting environment is displayed on the screen. The user aims the toy gun toward the screen, and the system tracks the gun position to control the aiming pointer.
The gun position is calculated using servo-based X and Y axis movement tracking. The position data is collected through the TTLinker interface and processed by the ESP32 controller. The ESP32 communicates the position data to the computer application, which controls the pointer movement according to the gun position.
When the user presses the trigger, the trigger switch detects the shooting action and sends an input signal to the ESP32. The ESP32 transmits the shooting command to the application, where the hit position is processed and the score is calculated based on the target location.
This project demonstrates embedded firmware development, servo control, hardware integration, real-time communication, and interactive system development.


---

## Project Images


![Image1](https://github.com/Sulfikarpk/Interactive-Gun-Shooting-system/blob/main/Gun_Project%20_image.jpeg)

![Image2](https://github.com/Sulfikarpk/Interactive-Gun-Shooting-system/blob/main/gun_mechanical_setup.jpeg)

---

## Project Video

testing1 https://youtube.com/shorts/4SQ0wr-eyJo?feature=share

testing2 https://youtu.be/zYuCQR-cJ6U

final_out https://youtu.be/kATsUKAYOL0

---

## Source Code 

code :- https://github.com/Sulfikarpk/Interactive-Gun-Shooting-system/blob/main/GUN.ino

---


## Hardware Components

- ESP32 Development Board
- Toy Gun Assembly
- Servo Motors for X-Y Axis Position Tracking
- TTLinker Communication Interface
- Trigger Switch
- Power Supply
- Supporting Electronic Components

---

## Software & Technologies

- Embedded C/C++
- ESP32 Firmware Development
- Servo Motor Control
- Serial Communication
- Hardware Interface Programming
- PC Application Communication
- Real-Time Data Processing

---

## System Working

1. The game application starts and displays the shooting environment on the screen.
2. The user aims the toy gun toward the displayed targets.
3. Servo motors calculate the X and Y axis movement of the gun.
4. The TTLinker interface reads the position values from the tracking system.
5. ESP32 receives and processes the position data.
6. ESP32 sends the gun position information to the computer application.
7. The application updates the pointer position according to the gun movement.
8. When the trigger is pressed, the trigger switch sends a signal to the ESP32.
9. ESP32 sends the shooting command to the application.
10. The application detects the target hit position and updates the score.

---

## System Architecture

```
                 Toy Gun
                    |
        -------------------------
        |                       |
    servo motor             Trigger Switch
        |                       |
   X Y positions             Input Signal
        |                       |
        -------- TTLinker -------
                    |
                  ESP32
                    |
          Serial Communication
                    |
          Computer Application
                    |
          Interactive Game
```

---

## Key Features

- Real-time interactive shooting gameplay
- Physical toy gun controller interface
- Servo-based X-Y axis position tracking
- Trigger-based shooting detection
- ESP32-based embedded control system
- Real-time communication between hardware and PC application
- Interactive pointer movement control
- Target detection and score calculation

---

## Skills Demonstrated

- Embedded Firmware Development
- ESP32 Programming
- Hardware and Software Integration
- Servo Motor Interfacing
- Motion Tracking System Development
- Communication Interface Implementation
- Real-Time Embedded System Design
- Debugging and Testing
- Interactive Product Development


---

## Applications

- Interactive gaming installations
- Exhibition and event technology
- Entertainment systems
- Training simulators
- Custom interactive experiences

---

## Author

**Sulfikar P.K.**  
Embedded Engineer  

GitHub:  
https://github.com/Sulfikarpk
