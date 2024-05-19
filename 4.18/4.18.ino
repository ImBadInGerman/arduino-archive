int messwert=0;

void setup() {
    Serial.begin(9600);
}

void loop(){
    messwert = analogRead(A0);
    Serial.print("Messwert: ");
    Serial.println(messwert);
    delay(100);
}
