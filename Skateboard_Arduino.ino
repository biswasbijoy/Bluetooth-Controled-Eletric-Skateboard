#define ENA 5
#define IN1 6
#define IN2 7

#include <SoftwareSerial.h>
SoftwareSerial BTserial(0, 1); // RX | TX

int speedA = 0;

void setup() {
  Serial.begin(9600);
  // Set pin modes
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  // Initialize Bluetooth serial
  BTserial.begin(9600);
}

void loop() {
  
// Read data from Bluetooth module
  while (BTserial.available()) {

    char command = BTserial.read();
    if (command == 'F') {
      speedA += 30;
    }
    else if (command == 'B') {
      speedA -= 30;
    }
    else if (command == 'S') {

      while(speedA>0){
        speedA-=30;
        delay(250);
        if(speedA<0)speedA=0;

        analogWrite(ENA, speedA);
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
      }

    }
  }
//
//   Constrain speed value
  speedA = constrain(speedA, 0, 255);

//   Set motor speed
  analogWrite(ENA, speedA);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

//  Stop motor if speed is zero
  if (speedA == 0) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }
//
// Wait for motor to respond
  delay(10);
}
