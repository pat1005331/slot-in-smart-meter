#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include "config.h"
#include <SoftwareSerial.h>
#include "Arduino.h"

class communication
{

private:
  SoftwareSerial esp8266; //rx,tx
  void wait_for_ok();
  
  
public:
	communication();

	int connectToNetwork();
	int connectToServer();
	byte sendData(float);


};



#endif
