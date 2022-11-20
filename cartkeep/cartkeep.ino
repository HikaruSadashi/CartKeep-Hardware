#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin(); // initialize the sensor
  Serial.println("New Sketch Uploaded!");
}

void loop() {
  // wait a few seconds between measurements.
  delay(1000);

  // read humidity
  float humi  = dht.readHumidity();
  // read temperature as Celsius
  float tempC = dht.readTemperature();
  // read temperature as Fahrenheit
  float tempF = dht.readTemperature(true);

  // check if any reads failed
  if (isnan(humi) || isnan(tempC) || isnan(tempF)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.print("Humidity: ");
    Serial.print(humi);
    Serial.print("%");

    Serial.print("  |  "); 

    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.print("C");
    Serial.print(tempF);
    Serial.println("F");

    /*
    Serial.print("°C ~ ");
    Serial.println("°F");
    */
    int baseline = 70;
    if(humi > baseline){
      Serial.println("Message sent to phone, person blowing!!!");
    }
  }

  /*
  Baseline: 
  Blowing does change it:
  Touching does change it a lot:
  

  */

  /*
    To reset
  */
}