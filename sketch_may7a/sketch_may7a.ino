#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(200);

  float humidity = dht.readHumidity();

  // For Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // For Serial Plotter
  Serial.println(humidity);
}