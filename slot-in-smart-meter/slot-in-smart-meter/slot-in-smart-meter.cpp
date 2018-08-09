
#include "config.h"
#include "communication.h"
#include "monitoring.h"
#include "switching.h"

communication comms;

void setup() {
	comms.connectToNetwork();
	
}

void loop() {
	comms.connectToServer();
	comms.sendData();
}