#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22

//wifi libraries
#include <WiFi.h>
#include <HTTPClient.h>
#include <sstream>

//SETUP HERE & SENDING SMS FUNCTION
//DONT EXPOSE API KEYS LMFAO


bool sendSMS(const char * body){
 
  std::stringstream url;
  url << "https://api.twilio.com/2010-04-01/Accounts/" << accountNr <<"/Messages";
 
  std::stringstream urlEncodedBody;
  urlEncodedBody << "MessagingServiceSid=" << messagingServiceSid << "&To=" << to << "&Body=" << body;
 
  Serial.print("\nURL: ");
  Serial.println(url.str().c_str());
  Serial.print("Encoded body: ");
  Serial.println(urlEncodedBody.str().c_str());
   
 
  HTTPClient http;
 
  http.begin(url.str().c_str());
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  http.setAuthorization(accountNr, twilioPassword);
   
  int httpCode = http.POST(urlEncodedBody.str().c_str());                                               
  
  if (httpCode > 0) {
 
      String payload = http.getString();
 
      Serial.print("\nHTTP code: ");
      Serial.println(httpCode);
 
      Serial.print("\nResponse: ");
      Serial.println(payload);
    }
 
  else {
    Serial.println("Error on HTTP request:");
    Serial.println(httpCode);
  }
 
  http.end();
 
  return httpCode == 201;
 
} //FUNCTION ENDS HERE
 
//READING SENSOR DATA function
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin(); // initialize the sensor
  Serial.println("New Sketch Uploaded!");

  //Connecting to wifi
  //Serial.begin(115200);
 
  WiFi.begin(ssid, password); 
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  
  Serial.println("Connected to the WiFi network");
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
    Serial.print("C , ");
    Serial.print(tempF);
    Serial.println("F");

    /* Old printing
    Serial.print("°C ~ ");
    Serial.println("°F");
    */

    int baseline = 70;
    if(humi > baseline){
      //function call
      bool result = sendSMS("Test SMS from ESP32!");
      Serial.println("Message sent to phone, person blowing!!!");
      if(resulttrue){
        Serial.println("Phone received message!")
      } else(result){
        Serial.println("Phone did NOT receive message!")
      }
      delay(6000)
    }
  }

  /*
  Baseline: 
  Blowing does change it:
  Touching does change it a lot:
  

  */

  /*  NOTES
    To upload new sketch:
    1. hold boot button then click en for enable to reset via RTS pin
  */
}
