
#include "config.h"
#include "switching.h"

void switching::setState(bool _state)
{
	state = _state;
	//if (state == 1) digitalWrite(relayPin, 1);	//open the relay
	//else digitalWrite(relayPin, 0);				//close the relay
}

bool switching::getState()
{
	return state;
}

switching::switching(int relayPin)
{
	//pinMode(relayPin, OUTPUT);
}
