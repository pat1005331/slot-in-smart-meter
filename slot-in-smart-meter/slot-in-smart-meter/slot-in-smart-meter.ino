
#include "config.h"
#include "communication.h"
#include "monitoring.h"
#include "switching.h"
#include "storage.h"

communication comms;
switching the_switch(12);	//connect relay transistor to pin 12
monitoring monitor(11);


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
