/*
  This Library is written for GPS parser
  Author: Bonezegei (Jofel Batutay)
  Date: July 2023 
*/
#ifndef _BONEZEGEI_GPS_H_
#define _BONEZEGEI_GPS_H_
#include <Arduino.h>
#include <Bonezegei_SoftSerial.h>

#define GPS_VALID 'A'

class Bonezegei_GPS {
public:

  Bonezegei_GPS();
  Bonezegei_GPS(HardwareSerial& serial);
  Bonezegei_GPS(Bonezegei_SoftSerial& serial);

  void begin();
  void begin(int baud);

  uint8_t getData();
  uint8_t getGPRMC();

  double latitude;
  double longitude;
  float speed;

  char sentence[90];
  int sentence_index;
  uint8_t sen_flag; //sentence flag for $ and * 
private:
  Bonezegei_SoftSerial* softserial;
  HardwareSerial *hardserial;
  uint8_t ser;  //serial selected 0 for hardware serial and 1 for softserial
};


#endif
