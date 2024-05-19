int Taster=6;
int Tasterstatus=0;

void setup() {
    pinMode(Taster, INPUT);
}

void loop() {
    Tasterstatus=digitalRead(Taster);
    if (Tasterstatus==HIGH){
        tone(8, 100);
        delay(1000);
        noTone(8);
    }
}