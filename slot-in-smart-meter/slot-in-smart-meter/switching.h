#ifndef SWITCHING_H
#define SWITCHING_H

#include "config.h"
#include "Arduino.h"

class switching {
private:
	
	int relayPin;
	

public:
	int state = 0;
	void setState(int);
	int getState();
	switching(int);
};

#endif