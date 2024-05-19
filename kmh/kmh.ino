const int echo = 7;
const int trigger = 8;
long entfernung1 = 0, entfernung2 = 0;
float speed = 0;

void setup() {
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);
    Serial.begin(9600);
}

long measureDistance() {
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);
    long distance = pulseIn(echo, HIGH);
    distance = (distance / 2) / 29.1; // convert to cm

    if (distance < 2 || distance > 400) {
        return 0; // ignore garbage readings
    } else {
        return distance;
    }
}

void loop() {
    // First measurement
    entfernung1 = measureDistance();
    long time1 = micros();

    delay(250); // wait for a while

    // Second measurement
    entfernung2 = measureDistance();

    if (entfernung1 != 0 && entfernung2 != 0) {
        // Calculate speed = distance / time
        speed = (entfernung2 - entfernung1) / ((micros() - time1) / 1000000.0); // speed in cm/s

        // Convert speed to km/h
        float speedKmh = speed * 0.036;

//        Serial.print("Speed: ");
//        Serial.print(speedKmh);
//        Serial.println(" km/h");

        Serial.println(speedKmh);
    }
}