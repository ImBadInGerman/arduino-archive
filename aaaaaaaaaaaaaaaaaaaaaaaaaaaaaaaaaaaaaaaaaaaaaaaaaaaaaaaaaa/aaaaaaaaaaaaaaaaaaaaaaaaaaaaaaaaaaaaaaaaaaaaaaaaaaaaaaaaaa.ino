#define PIN_SHIFT 8   // connected to SHCP
#define PIN_STORE 9   // connected to STCP
#define PIN_DATA  10  // connected to DS

byte count = 0;

// Binary count from 0-255:
// 1 = 000000001
// 2 = 000000010
// 3 = 000000011
// 4 = 000000100
// 5 = 000000101
// etc.

void setup()
{
  pinMode(PIN_STORE, OUTPUT);
  pinMode(PIN_SHIFT, OUTPUT);
  pinMode(PIN_DATA, OUTPUT);


  digitalWrite(PIN_STORE, LOW);
  shiftOut(PIN_DATA, PIN_SHIFT, LSBFIRST, count);
  digitalWrite(PIN_STORE, HIGH);

  delay(2000);
}

void loop ()
{
  digitalWrite(PIN_STORE, LOW);
  shiftOut(PIN_DATA, PIN_SHIFT, LSBFIRST, count);
  digitalWrite(PIN_STORE, HIGH);
  delay(250);

 count ++;
}