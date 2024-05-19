int TPM36 = A0;
int sensorwert;
int temperatur = 0;
int t=500;
int piezo=5;

void setup() {
  pinMode(piezo,OUTPUT);
  Serial.begin(9600);
}

void loop(){
    sensorwert=analogRead(TPM36);
    temperatur = map(sensorwert, 0, 410, -50, 150);
    Serial.print(temperatur);
    Serial.println("°C");

    if (temperatur>=30){
        digitalWrite(piezo,HIGH);
    }
    else{
        digitalWrite(piezo,LOW);
    }
}