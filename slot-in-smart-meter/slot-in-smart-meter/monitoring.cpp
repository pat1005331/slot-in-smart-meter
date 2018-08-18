
#include "config.h"
#include "monitoring.h"

monitoring::monitoring(int pin)
{
	CTPin = pin;
	pinMode(CTPin, INPUT);
}

float monitoring::readCT()
{
	float value = analogRead(A0);
	return value/**currentFactor*/;
}

float monitoring::calculatePower(float current)
{
	return(current * voltage);
}
