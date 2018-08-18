#ifndef MONITORING_H
#define MONITORING_H

/*
The CT transformer used it the Talema AS-103 it has a coil ratio of 300 : 1 and is rated to 15A. 
Use a 51ohm resistor to convert the transformer current to a ref voltage to read with the arduino.
*/

#include "config.h"
#include "Arduino.h"

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