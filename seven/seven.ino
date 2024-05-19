#include "SevSeg.h"
SevSeg sevseg;

void setup(){
    byte numDigits = 4;
    byte digitPins[] = {2, 3, 4, 5};
    byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
    sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
}

void loop() {
    for (int i = 1; i <= 100; i++) {
        sevseg.setNumber(i, 0);
        sevseg.setBrightness(90);
        unsigned long startTime = millis();
        while(millis() - startTime < 250) { // keep updating the display for 1 second
            sevseg.refreshDisplay();
        }
    }
}