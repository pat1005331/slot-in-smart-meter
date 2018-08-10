#pragma once

#include "config.h"
#include <SoftwareSerial.h>

class communication
{

  private:
  SoftwareSerial esp8266(10, 11); //rx,tx
  
public:
	communication();

	int connectToNetwork();
	int connectToServer();
	int sendData();



} comms;


