#include <SoftwareSerial.h>
#include "AFMotor.h"
#include <Arduino.h>
#define x A0
#define y A1
#define Speed 180

#define rxPin A2
#define txPin A3
#define yellow_left A1
#define yellow_right A0
#define white A4
#define red A5

AF_DCMotor motor1(3);
AF_DCMotor motor2(4);

SoftwareSerial mySerial(rxPin, txPin); // RX, TX pins for SoftwareSerial

void setup() {
  Serial.begin(9600); // Initialize the hardware serial port for debugging
  mySerial.begin(9600); // Initialize the software serial port
  motor1.setSpeed(Speed);
  motor2.setSpeed(Speed);
  pinMode(yellow_left, OUTPUT);
  pinMode(yellow_right, OUTPUT);
  pinMode(white, OUTPUT);
  pinMode(red, OUTPUT);
  digitalWrite(white, HIGH );
}

void loop() {
  if (mySerial.available()) {
    char data = mySerial.read();
    Serial.write(data);
    if (data == '1')  { // LEFT
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      digitalWrite(red, LOW);
      digitalWrite(yellow_left, HIGH);
      digitalWrite(yellow_right, LOW);
    } else if (data == '2') {     // RIGHT
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      digitalWrite(red, LOW);
      digitalWrite(yellow_left, LOW);
      digitalWrite(yellow_right, HIGH);
    } else if (data == '3') {     // FORWARD
      motor1.run(FORWARD);
      motor2.run(BACKWARD);
      digitalWrite(red, LOW);
      digitalWrite(yellow_left, LOW);
      digitalWrite(yellow_right, LOW);
    } else if (data == '4') {   // BACKWARD
      motor1.run(BACKWARD);
      motor2.run(FORWARD);
      digitalWrite(red, HIGH);
      digitalWrite(yellow_left, LOW);
      digitalWrite(yellow_right, LOW);
    } else if (data == '0') {   // STOP
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      digitalWrite(red, LOW);
      digitalWrite(yellow_left, HIGH);
      digitalWrite(yellow_right, LOW);
    }
    mySerial.write(data);
  }
}
