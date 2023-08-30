/*
  Author: Bonezegei (Jofel Batutay)
  Date: August 2023
  Tested using ESP32 
  Serial 2 GPS 
*/

#include <Bonezegei_GPS.h>
//declare GPS connected to Serial2
Bonezegei_GPS gps(Serial2);

void setup() {
  Serial.begin(9600);
  gps.begin(9600);  
}

void loop() {
  if(gps.getData()==GPS_VALID){
    Serial.printf("lat: %lf lon:%lf\n", gps.latitude,gps.longitude);
  }
}
