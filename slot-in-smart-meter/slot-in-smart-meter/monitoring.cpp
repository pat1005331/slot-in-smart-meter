
#include "config.h"
#include "monitoring.h"

monitoring::monitoring(int pin)
{
	CTPin = pin;
}

float monitoring::readCT()
{
  //int value = analogRead(A0);
	//return value/**currentFactor*/;
}

float monitoring::calculatePower(float current)
{
	return(current * voltage);
}
