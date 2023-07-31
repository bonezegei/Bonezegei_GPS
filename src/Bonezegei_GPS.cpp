/*
  This Library is written for GPS parser
  Author: Bonezegei (Jofel Batutay)
  Date: July 2023 
*/

#include "Bonezegei_GPS.h"

Bonezegei_GPS::Bonezegei_GPS() {
}

Bonezegei_GPS::Bonezegei_GPS(const HardwareSerial& se) {
  s = (HardwareSerial*)&se;
}

void Bonezegei_GPS::begin(){
  s->begin(9600);
}

void Bonezegei_GPS::begin(int baud){
  s->begin(baud);
}
