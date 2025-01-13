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
    char data = serialBT.read();
    // Process the received data here
    // Echo back the data to the serial port
    Serial.write(data);
    mySerial.write(data);
  }
}
