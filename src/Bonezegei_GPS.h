/*
  This Library is written for GPS parser
  Author: Bonezegei (Jofel Batutay)
  Date: July 2023 
*/
#ifndef _BONEZEGEI_GPS_H_
#define _BONEZEGEI_GPS_H_
#include <Arduino.h>

class Bonezegei_GPS {
public:

  Bonezegei_GPS();
  Bonezegei_GPS(const HardwareSerial& se);

  void begin();
  void begin(int baud);

  void log(){
    s->println("Bonezegei");
  }

private:
  HardwareSerial *s;
};


#endif
