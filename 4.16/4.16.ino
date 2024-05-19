#include <Stepper.h>

int SPU = 2048;

Stepper Motor(SPU, 3, 5, 4, 6);

int LED = 10;

int taster = 9;
int echo = 8;
int trigger = 7;

int tasterstatus = 0;
long dauer = 0;
long entfernung = 0;

void setup() {
    pinMode(LED, OUTPUT);
    Motor.setSpeed(5);
    Serial.begin(9600);
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);
    pinMode(taster, INPUT);
}

void loop() {
    tasterstatus = digitalRead(taster);
    digitalWrite(trigger, HIGH);
    delay(10);
    digitalWrite(trigger, LOW);
    dauer = pulseIn(echo, HIGH);
    entfernung = (dauer / 2) * 0.03432;
    tasterstatus = digitalRead(taster);

    if (entfernung <= 5) {
        Motor.step(512);
        delay(9000);
        digitalWrite(LED, HIGH);
        delay(3000);
        Motor.step(-512);
        digitalWrite(LED, LOW);
        delay(1000);
        
        if (tasterstatus == HIGH) {
            Motor.step(512);
            delay(9000);
            digitalWrite(LED, HIGH);
            delay(3000);
            Motor.step(-512);
            digitalWrite(LED, LOW);
            delay(1000);
        } else {
            digitalWrite(LED, LOW);
            Serial.println("Taster nicht gedrückt");
        }
        Serial.print(entfernung);
        Serial.println(" cm");
    }
}