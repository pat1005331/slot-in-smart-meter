
#include "config.h"
#include "switching.h"


void switching::setState(int _state)	//set the state of the switch, 0 = off 1 = on
{
	state = _state;
	if (state = 0) digitalWrite(relayPin, LOW);
	else digitalWrite(relayPin, HIGH);
}

int switching::getState()
{
	return state;
}

switching::switching(int relayPin)	//connect the relay transistor to relayPin so that LOW = closed switch
{
	pinMode(relayPin, OUTPUT);
	digitalWrite(relayPin, LOW); //set the state of the switch to the current state
}
