int LEDblau = 3;
int LEDrot = 5;
int LEDgruen = 6;
int p=1000;
int brightness1a = 150;
int brightness1b = 150;
int brightness1c = 150;
int dunkel = 0;

void setup() {
  pinMode(LEDblau, OUTPUT);
  pinMode(LEDrot, OUTPUT);
  pinMode(LEDgruen, OUTPUT);
}

void loop() {
    analogWrite(LEDblau, brightness1a);
    delay(p);
    analogWrite(LEDblau, dunkel);
    analogWrite(LEDrot, brightness1b);
    delay(p);
    analogWrite(LEDrot, dunkel);
    analogWrite(LEDgruen, brightness1c);
    delay(p);
    analogWrite(LEDgruen, dunkel);
}