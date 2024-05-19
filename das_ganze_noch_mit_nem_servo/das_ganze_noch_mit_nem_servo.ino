#include <Servo.h>

int rot=10;
int gelb=11;
int gruen=12;
int trigger=8;
int echo=7;
long entfernung=0;
long dauer=0;

Servo Motor;  // create servo object to control a servo

void setup() {
  Motor.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(rot, OUTPUT);
  pinMode(gelb, OUTPUT);
  pinMode(gruen, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT); 
  digitalWrite(gelb, LOW);
  digitalWrite(rot, HIGH);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigger, LOW);
  delay(1);
  digitalWrite(trigger, HIGH);
  delay(1);
  digitalWrite(trigger, LOW);
  dauer = pulseIn(echo, HIGH);
  entfernung = (dauer/2) * 0.03432;
  Serial.print("Entfernung: ");
  Serial.println(entfernung);
  if (entfernung <= 10){
    Serial.println("Rot");
    digitalWrite(gelb, LOW);
    digitalWrite(rot, HIGH);
    Motor.write(0);  // move servo to 0 degrees
    delay(5000);
    Serial.println("Gelb");
    digitalWrite(gelb, HIGH);
    delay(3000);
    Serial.println("Grün");
    digitalWrite(rot, LOW);
    digitalWrite(gelb, LOW);
    digitalWrite(gruen, HIGH);
    delay(5000);
    Serial.println("Gelb");
    digitalWrite(gruen, LOW);
    digitalWrite(gelb, HIGH);
    delay(3000);
    Serial.println("Rot");
    digitalWrite(gelb, LOW);
    digitalWrite(rot, HIGH);    
    Motor.write(180);  // move servo to 180 degrees
  }
  else
  {
    digitalWrite(rot, HIGH);
  }
}