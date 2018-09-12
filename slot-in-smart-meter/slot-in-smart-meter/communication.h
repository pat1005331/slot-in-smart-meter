#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include "config.h"
#include <SoftwareSerial.h>
#include "Arduino.h"
//#include "RestClient.h"

class communication
{

  private:
  SoftwareSerial esp8266; //rx,tx
  
  
public:
	communication();

	int connectToNetwork();
	int connectToServer();
	byte sendData(float);



};



#endif