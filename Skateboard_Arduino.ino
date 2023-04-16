#include <SoftwareSerial.h>

// Define software serial object
SoftwareSerial BTserial(0, 1); // RX | TX

// Define motor pins
const int leftMotorForwardPin = 4;
const int leftMotorBackwardPin = 5;
const int rightMotorForwardPin = 6;
const int rightMotorBackwardPin = 7;
const int rightSpeed = 10;
const int leftSpeed = 11;
int speedValue = 3;

void setup() {
  // Set motor pins as outputs
  pinMode(rightSpeed, OUTPUT);
  pinMode(leftSpeed, OUTPUT);
  pinMode(leftMotorForwardPin, OUTPUT);
  pinMode(leftMotorBackwardPin, OUTPUT);
  pinMode(rightMotorForwardPin, OUTPUT);
  pinMode(rightMotorBackwardPin, OUTPUT);

  // Begin serial communication with a baud rate of 9600
  Serial.begin(9600);

  // Begin Bluetooth communication with a baud rate of 9600
  BTserial.begin(9600);
}

int getSpeed(int x)
{
  int ans = (255 / 9) * x;
  return ans;
}

void loop() {
  // Read data from Bluetooth module

  while (BTserial.available()) {
    char command = BTserial.read();

    if (command >= '0' && command <= '9')
    {
      speedValue = command - '0';
      Serial.println(speedValue);


      continue;
    }
    Serial.println(command);

    // Move forward
    if (command == 'F') {
      analogWrite(leftSpeed, getSpeed(speedValue));
      digitalWrite(leftMotorForwardPin, HIGH);
      digitalWrite(leftMotorBackwardPin, LOW);
      digitalWrite(rightMotorForwardPin, HIGH);
      digitalWrite(rightMotorBackwardPin, LOW);
      analogWrite(rightSpeed, getSpeed(speedValue));

    }
    // Move backward
    else if (command == 'B') {
      digitalWrite(leftMotorForwardPin, LOW);
      digitalWrite(leftMotorBackwardPin, HIGH);
      digitalWrite(rightMotorForwardPin, LOW);
      digitalWrite(rightMotorBackwardPin, HIGH);
    }
    // Turn left
    else if (command == 'L') {
      digitalWrite(leftMotorForwardPin, LOW);
      digitalWrite(leftMotorBackwardPin, HIGH);
      digitalWrite(rightMotorForwardPin, HIGH);
      digitalWrite(rightMotorBackwardPin, LOW);
    }
    // Turn right
    else if (command == 'R') {
      digitalWrite(leftMotorForwardPin, HIGH);
      digitalWrite(leftMotorBackwardPin, LOW);
      digitalWrite(rightMotorForwardPin, LOW);
      digitalWrite(rightMotorBackwardPin, HIGH);
    }
    // Stop
    else if (command == 'S') {
      digitalWrite(leftMotorForwardPin, LOW);
      digitalWrite(leftMotorBackwardPin, LOW);
      digitalWrite(rightMotorForwardPin, LOW);
      digitalWrite(rightMotorBackwardPin, LOW);
    }
  }
}
