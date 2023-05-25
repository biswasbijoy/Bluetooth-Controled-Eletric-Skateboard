#define led1 8
#define led2 9
#define buzzer 3
#define trigPin 10
#define echoPin 11


#include<NewPing.h>

NewPing sonar(trigPin, echoPin, 100);

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {

 digitalWrite(led1, HIGH);
 digitalWrite(led2, LOW);
 delay(200);
 digitalWrite(led1, LOW);
 digitalWrite(led2, HIGH);
 delay(200);

 float cm = sonar.ping_cm();
 if(cm == 0) {
  cm = 100;
 }

 if(cm <= 41.789) {
  digitalWrite(buzzer, HIGH);
 }

 else {
  digitalWrite(buzzer, LOW);
 }
  // put your main code here, to run repeatedly:

}
