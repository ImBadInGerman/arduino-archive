#include <Servo.h>
Servo servoblau;

void setup() {
    servoblau.attach(8);
}

void loop() {
    servoblau.write(0);
    delay(1000);
    servoblau.write(90);
    delay(1000);
    servoblau.write(180);
    delay(1000);
}