//include servo
#include <Servo.h>
int echo = 7;
int trigger = 8;
int rot = 2;
int gelb = 3;
int gruen = 4;

long entfernung;

Servo servo;
void setup() {
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
  pinMode(rot, OUTPUT);
  pinMode(gelb, OUTPUT);
  pinMode(gruen, OUTPUT);
  servo.attach(9);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  entfernung = pulseIn(echo, HIGH) / 58.2;
  Serial.println(entfernung);
  delay(100);
  if (entfernung < 10) {
    digitalWrite(rot, HIGH);
    digitalWrite(gelb, LOW);
    digitalWrite(gruen, LOW);
    servo.write(0);
  } else {
    digitalWrite(rot, LOW);
    digitalWrite(gelb, LOW);
    digitalWrite(gruen, HIGH);
    servo.write(90);
  }
}
