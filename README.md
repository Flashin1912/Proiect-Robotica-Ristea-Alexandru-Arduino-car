# Remote Control Car
## Table of Contents
[1. Introduction](#introduction)\
[2. Overview](#overview)\
[3. Hardware Design](#hardware-design)\
[4. Software Design](#software-design)\
[5. Final Results](#introduction)\
[6. Introduction](#final-results)\
[7. Conclusion](#conclusion)\
[8. Source Code](#source-code)\
[9. Resources](#resources)



## Introduction
In an era of interconnected devices, integrating everyday technology with remote control systems provides innovative solutions for entertainment and practical applications. This project focuses on creating a remote-controlled car that bridges traditional toy car design with modern smartphone capabilities.

This compact vehicle is designed to be operated via a mobile app, offering a seamless and interactive user experience. By leveraging Bluetooth technology, users can navigate the car with precision and ease. The project emphasizes both hardware engineering and software development, providing a functional and engaging platform that showcases the potential of mobile-controlled systems.

## Overview
### Detailed Description of Hardware Functionality and Components Used:
1. **Microcontroller - Arduino Uno** ---- The Arduino Uno is a microcontroller board based on the ATmega328P. It features 14 digital input/output pins, 6 analog inputs, a 16 MHz quartz crystal, and USB connectivity. It is the core of the project, coordinating all inputs and outputs.
   
2.  **Shield driver motor stepper L293D** ---- Using an L293D motor driver IC with an Arduino is an excellent way to achieve precise DC motor control. The module allows the control of DC motors both forward and backward. It enables the Arduino to manage the high current and voltage requirements of the motors safely.The shield module supports 4 DC motors, 2 steppers or 2 servomotors.

3.  **4 TT Motors** ---- They are basically DC motors that run by injecting them to a DC source like a battery or a DC coupler. They are controlled by the Arduino through the motor stepper.

4.  **4 Mecanum Wheels** ---- A Mecanum wheel is an omnidirectional wheel design for a land-based vehicle to move in any direction. It consists of a series of rubberized external rollers set at a 45° angle to the wheel. Each wheel is independently-driven, and the direction of travel is dependent on the interaction between the directions each wheel is driven in relative to the others.

5.  **Breadboard** ---- A breadboard is a construction base used to build semi-permanent prototypes of electronic circuits.

6.  **ESP32 DEVKITV1** ---- The ESP32 module has integrated antenna and RF balun, power amplifier, power management module, filters and low noise amplifiers.
The board contains Wi-Fi, Bluetooth and a dual-core processor.

7.  **9V Battery** ---- The 9V battery supplies power to the L293D motor driver module, respectively to the Arduino

8.  **External Batterry** ---- An external battery that provides power to the ESP32 module

9.  **Wires** ---- Lots of wires that make the connections possible

10.  **Resistors** ---- Used for the transfer between the different power voltages of the Arduino and the ESP32

11.  *(Optional)* **Joystick** ---- A precaution in case the batteries of the car run out

## Hardware Design
| Component                           | Quantity | Description                                                                                 | Datasheet/Link                                                                 |
|-------------------------------------|----------|---------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------|
| Arduino Uno                         | 1        | Microcontroller based on ATmega328P. Coordinates inputs and outputs.                       | [Datasheet](https://docs.arduino.cc/resources/datasheets/A000066-datasheet.pdf) |
| Shield Driver Motor Stepper L293D   | 1        | Controls DC motors forward and backward. Supports DC motors, steppers, or servos.          | [Datasheet](https://www.ti.com/lit/ds/symlink/l293.pdf)                          |
| TT Motors                           | 4        | DC motors controlled by the Arduino via the motor driver.                                  | [Datasheet](https://www.verical.com/datasheet/adafruit-brushless-dc-motors-3777-5912007.pdf)         |
| Mecanum Wheels                      | 4        | Omnidirectional wheels with external rollers set at 45° for multidirectional movement.      | [Info](https://en.wikipedia.org/wiki/Mecanum_wheel)                              |
| Breadboard                          | 1        | Construction base for building semi-permanent electronic circuit prototypes.               | [Info](https://en.wikipedia.org/wiki/Breadboard)                                 |
| ESP32 DEVKITV1                      | 1        | Dual-core processor with Wi-Fi, Bluetooth, and power management.                          | [Datasheet](https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf) |
| 9V Battery                          | 1        | Supplies power to the L293D motor driver and Arduino.                                      | N/A                                                                            |
| External Battery                    | 1        | Provides power to the ESP32 module.                                                       | N/A                                                                            |
| Wires                               | Multiple | Connect components in the circuit.                                                        | N/A                                                                            |
| Resistors                           | Multiple | Used for power transfer between Arduino and ESP32.                                         | N/A

| Joystick (Optional)                 | 1        | Backup control method in case the car's batteries run out.                                 | [Datasheet](https://components101.com/sites/default/files/component_datasheet/Joystick%20Module.pdf) |


## Software Design

## Final Results

## Introduction

## Conclusion

## Source Code

Code for the Arduino Uno:
```#include <SoftwareSerial.h>
#include "AFMotor.h"
#include <Arduino.h>
#define x A0
#define y A1
#define Speed 180

#define rxPin A4
#define txPin A5

AF_DCMotor motor1(3);
AF_DCMotor motor2(4);

SoftwareSerial mySerial(rxPin, txPin); // RX, TX pins

void setup() {
  Serial.begin(9600); // Serial port for sending data through USB
  mySerial.begin(9600); // Serial port for sending data trough  Bluetooth
  motor1.setSpeed(Speed);
  motor2.setSpeed(Speed);
}

void loop() {
  if (mySerial.available()) {
    String data = mySerial.readString();
    Serial.println(data);
    if (data == 'STANGA')  {
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
    } else if (data == 'DREAPTA') {
      motor1.run(FORWARD);
      motor2.run(FORWARD);
    } else if (data == 'SPATE') {
      motor1.run(FORWARD);
      motor2.run(BACKWARD);
    } else if (data == 'INAINTE') {
      motor1.run(BACKWARD);
      motor2.run(FORWARD);
    } else if (data == 'STOP') {
      motor1.run(RELEASE);
      motor2.run(RELEASE);
    }
    mySerial.println(data);
  }
}
```

Code for ESP32:
```
#include <Arduino.h>
#include "BluetoothSerial.h"
#define TXD1 19
#define RXD1 21

HardwareSerial mySerial(1);
BluetoothSerial serialBT;

int counter = 0;

void setup() {
  Serial.begin(9600);
  serialBT.begin("Esp32-BT");
  mySerial.begin(9600, SERIAL_8N1, RXD1, TXD1); 
}

void loop() {
  if (serialBT.available()) {
    String data = serialBT.readString();
    Serial.println(data);
    mySerial.println(data);
  }
}
```


## Resources


















## Journal

This is a render of the idea I had for the project made in Blender.
The sizes of the components are not to scale, I made it just so we can have a rough idea of how it will look:
![Screenshot_20241209-010212_Word](https://github.com/user-attachments/assets/4ccc0243-d8dc-4d2d-a10a-a843d4fcf1e4)
Nothing complicated so far: a car that can drive forwards and backwards(and hopefully stir left and right), with headlight acting as such. Maybe more options added later

## Components
●Arduino Board
●Wheels
●Power Supply(4 AA Batteries)
●LEDs
●Wires



