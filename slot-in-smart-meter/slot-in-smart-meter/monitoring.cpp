
#include "config.h"
#include "monitoring.h"

monitoring::monitoring(int pin)
{
	CTPin = pin;
}

float monitoring::readCT()
{
	return analogRead(CTPin)*currentFactor;
}

float monitoring::calculatePower(float current)
{
	return(current * voltage);
}
