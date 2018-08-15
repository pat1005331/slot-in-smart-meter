#ifndef MONITORING_H
#define MONITORING_H

#include "config.h"

class monitoring
{
public:
	monitoring(int);

private:
	int CTPin;
	float readCT();
	float calculatePower(float);

	int voltage = 240;
	int currentFactor;
};


#endif