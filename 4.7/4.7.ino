int piezo=5;
int bewegung=7;
int bewegungstatus=0;

void setup() {
  pinMode(piezo,OUTPUT);
  pinMode(bewegung,INPUT);
}

void loop(){
    bewegungstatus=digitalRead(bewegung);
    if (bewegungstatus==HIGH){
        digitalWrite(piezo,HIGH);
        delay(5000);
        digitalWrite(piezo,LOW);
    }
    else{
        digitalWrite(piezo,LOW);
    }
}