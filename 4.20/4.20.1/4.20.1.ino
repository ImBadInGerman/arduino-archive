#include <Keypad.h>
const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

//const byte COLS = 3;
//byte colPins[COLS] = {8, 7, 6};
//char hexaKeys[ROWS][COLS] = {
//    {'1','2','3'},
//    {'4','5','6'},
//    {'7','8','9'},
//    {'*','0','#'}
//};
byte colPins[COLS] = {9, 8, 7, 6};
byte rowPins[ROWS] = {5, 4, 3, 2};
Keypad Tastenfeld = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
    Serial.begin(9600);
}

void loop() {
    char Taste = Tastenfeld.getKey();
    if (Taste) {
        Serial.print(Taste);
        Serial.print(" gedrueckt")
        Serial.println();
    }
}