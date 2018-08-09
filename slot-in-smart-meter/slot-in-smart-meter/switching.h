#pragma once

#include "config.h"

class switching {
private:
	bool state;

public:
	void setState(bool);
	bool getState();
	switching(int);
};
