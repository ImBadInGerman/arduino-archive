#include <Stepper.h>

int SPU = 2048;
Stepper Motor(SPU, 3,5,4,6);
int Taster=10;
int tasterstatus=0;

void setup() {
    Motor.setSpeed(4);
    pinMode(Taster,INPUT);
}

void loop(){
    tasterstatus=digitalRead(Taster);
    while (tasterstatus==HIGH){
        delay(1);
        tasterstatus=digitalRead(Taster);
    }
    Motor.step(1);
}