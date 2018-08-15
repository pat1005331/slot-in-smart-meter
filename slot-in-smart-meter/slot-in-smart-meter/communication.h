#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include "config.h"
#include <SoftwareSerial.h>

class communication
{

  private:
  SoftwareSerial esp8266; //rx,tx
  
  
public:
	communication();

	int connectToNetwork();
	int connectToServer();
	int sendData(int);



};



#endif