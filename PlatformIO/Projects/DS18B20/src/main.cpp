// ****************************************************************** 
// Dallas Semiconductor DS18B20 Temperature Sensor Demo Program 
// COMP-10184 
// Mohawk College 


// library for Arduino framework
#include <Arduino.h>

// 1-Wire sensor communication libary 
#include <OneWire.h> 

// DS18B20 sensor library 
#include <DallasTemperature.h>

  // Pin that the DS18B20 is connected to
  const int oneWireBus = D3;

  // Setup a oneWire instance to communicate with any OneWire devices
  OneWire oneWire(oneWireBus);

  // Pass our oneWire reference to Dallas Temperature sensor 
  DallasTemperature DS18B20(&oneWire);

  // variable to store DS18B20 advanced sensor unique address
  DeviceAddress sensorID = {};
  


void setup() {
  // configure the USB serial monitor
  Serial.begin(115200);

  // Start the DS18B20 sensore
  DS18B20.begin(); 

  byte deviceAddress = DS18B20.getAddress(sensorID, 0);

  // title
  Serial.println("Temperature Application");

  // Display DS18B20 Advanced Sensor unique address
  Serial.println("Found advanced sensor with unique address: " + String(deviceAddress));
  

}

void loop() {
  // put your main code here, to run repeatedly:

  float fTemp;

  // ask DS18B20 for the current temperature
  DS18B20.requestTemperatures();

  // fetch the temperature. We only have 1 sensor, so the index is 0.
  fTemp = DS18B20.getTempCByIndex(0);

  if (fTemp < 10) {
     // print the temp to the USB serial monitor
    Serial.println("Current temperature is: " + String(fTemp) + " deg. Celsius or Cold!");
  }

  if (fTemp >= 10 && fTemp <= 15) {
    // print the temp to the USB serial monitor
    Serial.println("Current temperature is: " + String(fTemp) + " deg. Celsius or Cool");
  }


  if (fTemp >= 15 && fTemp <= 25 ) {
      // print the temp to the USB serial monitor
    Serial.println("Current temperature is: " + String(fTemp) + " deg. Celsius or Perfect");
  }


  if (fTemp >= 25 && fTemp <= 30 ) {
     // print the temp to the USB serial monitor
    Serial.println("Current temperature is: " + String(fTemp) + " deg. Celsius or Warm");
  }

  if ( fTemp >= 30 && fTemp <= 35) {
     // print the temp to the USB serial monitor
    Serial.println("Current temperature is: " + String(fTemp) + " deg. Celsius or Hot");
  }

  if ( fTemp > 35) {
     // print the temp to the USB serial monitor
    Serial.println("Current temperature is: " + String(fTemp) + " deg. Celsius or Too Hot");
  }

  // wait 2s (2000ms) before doing this again 
  delay(2000);

}