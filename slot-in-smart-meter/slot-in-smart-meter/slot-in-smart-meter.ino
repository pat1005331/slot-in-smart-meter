
#include "config.h"
#include "communication.h"
#include "monitoring.h"
#include "switching.h"

communication comms;


void setup() {
	Serial.begin(115200);
	Serial.println("hi2");
	Serial.print("AT+CWJAP_CUR=\"OPTUS_63B07D\",\"entervatic65647\"");
	comms.connectToNetwork();
	Serial.println("connectToNetwork");
}



void loop() {
	comms.connectToServer();
	Serial.println("connectToServer");
	comms.sendData();
	Serial.println("send");
	delay(5000);
}
