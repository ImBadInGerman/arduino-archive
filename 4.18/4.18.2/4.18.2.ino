int messwert=0;
int PIEPS=6;

void setup() {
    Serial.begin(9600);
    pinMode(PIEPS, OUTPUT);
}

void loop(){
    messwert = analogRead(A0);
    Serial.print("Messwert: ");
    Serial.println(messwert);
    delay(100);
    if(messwert>400){
        digitalWrite(PIEPS, HIGH);
    }else{
        digitalWrite(PIEPS, LOW);
    }
}