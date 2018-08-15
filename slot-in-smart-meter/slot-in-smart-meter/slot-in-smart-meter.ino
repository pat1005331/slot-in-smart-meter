
#include "config.h"
#include "communication.h"
#include "monitoring.h"
#include "switching.h"

communication comms;


void setup() {
	Serial.begin(115200);
	Serial.println("hi");
	comms.connectToNetwork();
	Serial.println("connectToNetwork");
}



void loop() {
	comms.connectToServer();
	Serial.println("connectToServer");
	comms.sendData(9);
	Serial.println("send");
	delay(5000);
}
