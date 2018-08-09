#pragma once

#include "config.h"
#include <SoftwareSerial.h>

class communication
{
public:
	communication();

	int connectToNetwork();
	int connectToServer();
	int sendData();

private:

};


