#include <Servo.h>
#include <SevSeg.h>

SevSeg sevseg; //Instantiate a seven segment controller object

int rot=10;
int gelb=6;
int gruen=13;
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
  
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_CATHODE; // See README.md for options
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = true; // Use 'true' if your decimal point doesn't exist or isn't connected. Then, you only need to specify 7 segmentPins[]

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(90);
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
  sevseg.setNumber(entfernung, 2);
  sevseg.refreshDisplay(); 
  delay(250);
  if (entfernung <= 10){
    Serial.println("Rot");
    digitalWrite(gelb, LOW);
    digitalWrite(rot, HIGH);
    Motor.write(0);  // move servo to 0 degrees
    delay(5000);
    Serial.println("Gelb");
    digitalWrite(gelb, HIGH);
    delay(3000);
    Serial.println("Gruen");
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