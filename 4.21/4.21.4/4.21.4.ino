int Taster1=6;
int Taster2=7;
int Tasterstatus1=0;
int Tasterstatus2=0;

void setup() {
    pinMode(Taster1, INPUT);
    pinMode(Taster2, INPUT);
}

void loop() {
    Tasterstatus1=digitalRead(Taster1);
    Tasterstatus2=digitalRead(Taster2);
    if (Tasterstatus1==HIGH){
        tone(8, 100);
        delay(1000);
        noTone(8);
    }
    if (Tasterstatus2==HIGH){
        tone(8, 100);
        delay(1000);
        noTone(8);
    }
}