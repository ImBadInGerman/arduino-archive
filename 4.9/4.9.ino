int eingang=A0;
int LED=13;
int sensorwert=0;

void setup() {
  pinMode(LED,OUTPUT);
}

void loop(){
    sensorwert=analogRead(eingang);
    digitalWrite(LED,HIGH);
    delay(sensorwert);
    digitalWrite(LED,LOW);
    delay(sensorwert);
}