/*
  This Library is written for GPS parser
  Author: Bonezegei (Jofel Batutay)
  Date: July 2023 
*/

#include "Bonezegei_GPS.h"

Bonezegei_GPS::Bonezegei_GPS() {
}

Bonezegei_GPS::Bonezegei_GPS(HardwareSerial& serial) {
  hardserial = (HardwareSerial*)&serial;
  ser = 0;
}

Bonezegei_GPS::Bonezegei_GPS(Bonezegei_SoftSerial& serial) {
  ser = 1;
  softserial = (Bonezegei_SoftSerial*)&serial;
}

void Bonezegei_GPS::begin() {
  if (ser == 1) {
    softserial->begin(9600);
  } else {
    hardserial->begin(9600);
  }
}

void Bonezegei_GPS::begin(int baud) {
  if (ser == 1) {
    softserial->begin(baud);
  } else {
    hardserial->begin(baud);
  }
}


uint8_t Bonezegei_GPS::getData() {
  char ch = 0;
  if (ser == 1) {
    if (softserial->available()) {
      ch = softserial->read();
    }
  } else {
    if (hardserial->available()) {
      ch = hardserial->read();
    }
  }

  if (ch) {
    if (ch == '$') {
      sen_flag = 1;
    } else if (ch == '*') {
      sen_flag = 2;
    }

    if (sen_flag == 1) {
      sentence[sentence_index] = ch;
      sentence_index++;
    } else if (sen_flag == 2) {

      Serial.print("Sen:");
      for (int a = 0; a < sentence_index; a++) {
        Serial.write(sentence[a]);
      }
      Serial.println("");
      sentence_index = 0;
      sen_flag = 0;
    }
  }
  return 0;
}
