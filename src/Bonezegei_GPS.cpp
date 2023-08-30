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
      sentence_index = 0;
      sen_flag = 0;
      return getGPRMC();
    }
  }
  return 0;
}


uint8_t Bonezegei_GPS::getGPRMC() {
  char valid=0;
  const char s[2] = ",";
  char* data;
  data = strtok(sentence, s);
  double tmp_lat = 0;
  double tmp_lon = 0;

  unsigned char index = 0;
  if (strcmp(data, "$GPRMC") == 0) {
    while (data != NULL) {
      //Serial.printf("T: %s\n", data);

      //Time
      if (index == 1) {

      } 
      //validity
      else if (index == 2) {
        valid=data[0];
      }  // Lattitude
      else if (index == 3) {
        tmp_lat = atol(data);
        tmp_lat /= 100;
        int lat = (int)tmp_lat;
        latitude = lat + (((tmp_lat - lat) / 60)*100);
      } else if (index == 4) {
      }
      // Longitude
      else if (index == 5) {
        tmp_lon = atol(data);
        tmp_lon /= 100;
        int lon = (int)tmp_lon;
        longitude = lon + (((tmp_lon - lon) / 60)*100);
      }
      index++;
      data = strtok(NULL, s);
    }
  }
  return valid;
}
