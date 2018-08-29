#ifndef SWITCHING_H
#define SWITCHING_H

#include "config.h"
#include "Arduino.h"

class switching {
private:
	bool state = 0;
	int relayPin;

public:
	void setState(bool);
	bool getState();
	switching(int);
};

#endif