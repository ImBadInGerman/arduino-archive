int LED=9;
int helligkeit=0;
int x=5;

void setup() {
  pinMode(LED,OUTPUT);
}

void loop(){
    analogWrite(LED,helligkeit);
    helligkeit=helligkeit+x;
    delay(25);
    if(helligkeit==0 || helligkeit==255){
        x= -x;
    }
}