#include <Arduino.h>
#include <AFMotor.h>
#define x A2
#define y A3
#define Speed 180

#define yellow_left A1
#define yellow_right A0
#define white A4
#define red A5

AF_DCMotor motor1(3);
AF_DCMotor motor2(4);

void setup() {
  Serial.begin(9600);
  motor1.setSpeed(Speed);
  motor2.setSpeed(Speed);
  pinMode(yellow_left, OUTPUT);
  pinMode(yellow_right, OUTPUT);
  pinMode(white, OUTPUT);
  pinMode(red, OUTPUT);
  digitalWrite(white, HIGH );
}

void loop() {
  int X = analogRead(x);
  int Y = analogRead(y);

  Serial.print(X);
  Serial.print("\t");
  Serial.println(Y);

  if (X >= 800) {
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    digitalWrite(red, LOW);
    digitalWrite(yellow_left, HIGH);
    digitalWrite(yellow_right, LOW);
    digitalWrite(white, HIGH );
  } else if (X <= 200) {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    digitalWrite(red, LOW);
    digitalWrite(yellow_left, LOW);
    digitalWrite(yellow_right, HIGH);
    digitalWrite(white, HIGH );
  } else if (Y >= 800) {
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    digitalWrite(red, LOW);
    digitalWrite(yellow_left, LOW);
    digitalWrite(yellow_right, LOW);
    digitalWrite(white, HIGH );
  } else if (Y <= 200) {
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    digitalWrite(red, HIGH);
    digitalWrite(yellow_left, LOW);
    digitalWrite(yellow_right, LOW);
    digitalWrite(white, HIGH );
  } else {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    digitalWrite(red, LOW);
    digitalWrite(yellow_left, LOW);
    digitalWrite(yellow_right, LOW);
    digitalWrite(white, HIGH );
  }
}
