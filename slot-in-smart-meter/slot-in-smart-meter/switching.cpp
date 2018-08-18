
#include "config.h"
#include "switching.h"


void switching::setState(bool _state)	//set the state of the switch, 0 = off 1 = on
{
	state = _state;
	digitalWrite(relayPin, state);
}

bool switching::getState()
{
	return state;
}

switching::switching(int relayPin)	//connect the relay transistor to relayPin so that LOW = closed switch
{
	pinMode(relayPin, OUTPUT);
	digitalWrite(relayPin, state); //set the state of the switch to the current state
}
