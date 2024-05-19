int eingang=A0;
int LED=10;
int sensorwert=0;

void setup() {
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}

void loop(){
    sensorwert=analogRead(eingang);
    Serial.println(sensorwert);
    if(sensorwert>500){
        digitalWrite(LED,HIGH);
    }
    else{
        digitalWrite(LED,LOW);
    }
}