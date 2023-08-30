/*
  Author: Bonezegei (Jofel Batutay)
  Date: August 2023
  Tested using ESP32 
  Bonezegei SoftSerial GPS 
*/


#include "Bonezegei_GPS.h"

//RX TX
Bonezegei_SoftSerial softSerial(25,26);
Bonezegei_GPS gps(softSerial);

void setup() {
  Serial.begin(9600);
  gps.begin(9600);  
}

void loop() {
  if(gps.getData()==GPS_VALID){
    Serial.printf("lat: %lf lon:%lf\n", gps.latitude,gps.longitude);
  }
}
