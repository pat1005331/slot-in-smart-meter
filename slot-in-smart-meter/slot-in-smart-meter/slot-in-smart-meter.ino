
#include "config.h"
#include "communication.h"
#include "monitoring.h"
#include "switching.h"
#include "storage.h"

communication comms;
//switching the_switch(13);	//connect relay to pin A1
monitoring monitor(A0);

byte inputCommand;
int relayPin = 13;


void setup() {
	Serial.begin(115200);
	Serial.println("hi");
	comms.connectToNetwork();
	Serial.println("connectToNetwork");
}



void loop() {
	/*
	every 5 seconds:
	monitor and log power
	read 
	
	*/

	//comms.connectToServer();
	//Serial.println("connectToServer");
	//comms.sendData(9);
	//Serial.println("send");


	if (Serial.available()) {
		inputCommand = Serial.read(); 
		Serial.write(inputCommand);

		if (inputCommand == 49) {
			digitalWrite(relayPin, HIGH);

		}
		else if (inputCommand == 48) {
			digitalWrite(relayPin, LOW);

		}
	}
	
	

	//Serial.print("The switch is ");
	//Serial.println(the_switch.getState());
	//Serial.print("The current power consumption is ");
	//Serial.println(monitor.calculatePower());
}
