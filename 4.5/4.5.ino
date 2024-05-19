int LEDblau=6;
int taster=7;
int tasterstatus=0;

void setup() {
  pinMode(LEDblau,OUTPUT);
  pinMode(taster,INPUT);
}

void loop(){
    tasterstatus=digitalRead(taster);
    if (tasterstatus==HIGH){
        digitalWrite(LEDblau,HIGH);
        delay(5000);
        digitalWrite(LEDblau,LOW);
    }
    else{
        digitalWrite(LEDblau,LOW);
    }
}