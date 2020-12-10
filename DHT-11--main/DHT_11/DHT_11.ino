#include <DHT.h>
#include <DHT_U.h>

#include "DHT.h"
#define DHTPIN 16
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

void setup(){
  Serial.begin(9600);
  Serial.print(F("DHT11 test!"));
}
void loop(){
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if(isnan(h)||isnan(t)){
    Serial.println(F("Failed to read from DHT sensor"));
    return;
  }
  Serial.print(F("Humidity"));
  Serial.print(h);
  Serial.print(F("% Temperature: "));
  Serial.print(t);
  Serial.print(F("C"));
}
  
