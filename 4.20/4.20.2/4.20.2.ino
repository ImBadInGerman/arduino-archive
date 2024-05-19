#include <Keypad.h>
#include <Servo.h>

char P1='1';
char P2='2';
char P3='3';
char P4='A';

char C1, C2, C3, C4;

Servo servoblau;
int roteLED=12
int grueneLED=13

const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};
byte colPins[COLS] = {2, 3, 4, 5};
byte rowPins[ROWS] = {6, 7, 8, 9};

char Taste;

Keypad Tastenfeld = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
    Serial.begin(9600);
    servoblau.attach(11);
    pinMode(roteLED, OUTPUT);
    pinMode(grueneLED, OUTPUT);
}
void loop() {
    Anfang:
    Taste = Tastenfeld.getKey();
    if (Taste){
        if (Taste='*'){
            Serial.println("Türe ist verriegelt");
            delay(1000);
            servoblau.write(90);
            digitalWrite(roteLED, HIGH);
            digitalWrite(grueneLED, LOW);
            z1=0; z2=1; z3=1; z4=1;
            goto Anfang;
        }
        
        if (Taste='#'){
            if (C1==P1 && C2==P2 && C3==P3 && C4==P4){
                Serial.println("Türe ist entriegelt");
                delay(1000);
                servoblau.write(0);
                digitalWrite(roteLED, LOW);
                digitalWrite(grueneLED, HIGH);
                z1=0; z2=1; z3=1; z4=1;
                goto Anfang;
        }

        if (z1==0){
        C1=Taste;
        Serial.print("Die Taste ");
        Serial.print(C1);
        Serial.println(" wurde gedrückt");
        z1=1; z2=0; z3=1; z4=1;
        }

        if (z2==0){
            C2=Taste;
            Serial.print("Die Taste ");
            Serial.print(C2);
            Serial.println(" wurde gedrückt");
            z1=1; z2=1; z3=0; z4=1;
        }

        if (z3==0){
            C3=Taste;
            Serial.print("Die Taste ");
            Serial.print(C3);
            Serial.println(" wurde gedrückt");
            z1=1; z2=1; z3=1; z4=0;
        }

        if (z4==0){
            C4=Taste;
            Serial.print("Die Taste ");
            Serial.print(C4);
            Serial.println(" wurde gedrückt");
            z1=1; z2=1; z3=1; z4=1;
        }
    }
}