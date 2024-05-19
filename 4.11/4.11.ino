int trigger=3;
int echo=4;
long dauer=0;
long entfernung=0;

void setup() {
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}

void loop(){
    digitalWrite(trigger,LOW);
    delayMicroseconds(2);
    digitalWrite(trigger,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger,LOW);
    dauer=pulseIn(echo,HIGH);
    entfernung=dauer*0.034/2;
    if (entfernung>=500 || entfernung<=0){
        Serial.println("Kein Messwert");
    }
    else{
        Serial.print(entfernung);
        Serial.println("cm");
    }
    delay(1000);
}