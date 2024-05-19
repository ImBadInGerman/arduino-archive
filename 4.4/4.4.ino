int LED=4;
int pieps=5;

void setup() {
  pinMode(LED,OUTPUT);
  pinMode(pieps,OUTPUT);
}

void loop(){
    digitalWrite(LED, HIGH);
    digitalWrite(pieps, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    digitalWrite(pieps, LOW);
    delay(1000);
}