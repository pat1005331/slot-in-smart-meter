
#include "config.h"
#include "monitoring.h"

monitoring::monitoring(int pin)
{
	CTPin = pin;
	pinMode(CTPin, INPUT);

}

float monitoring::calculatePower()
{
	int current = 0;
	int maxCurrent = 0;
	int minCurrent = 1000;
	for (int i = 0; i <= 200; i++)  //Monitors and logs the current input for 200 cycles to determine max and min current
	{
		current = analogRead(CTPin);    //Reads current input and records maximum and minimum current
		if (current >= maxCurrent)
			maxCurrent = current;
		else if (current <= minCurrent)
			minCurrent = current;
	}

	float midpoint = (minCurrent + maxCurrent) / 2.0;
	float maxAmplitude = (maxCurrent - midpoint);
	float RMSCurrent = maxAmplitude * 0.7071 * scaleFactor;
	return voltage * RMSCurrent;

}
