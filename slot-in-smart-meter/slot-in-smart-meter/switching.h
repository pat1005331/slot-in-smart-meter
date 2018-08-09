#pragma once

#include "config.h"

class switching {
private:
	bool state;
  int relayPin;

public:
	void setState(bool);
	bool getState();
	switching(int);
};
