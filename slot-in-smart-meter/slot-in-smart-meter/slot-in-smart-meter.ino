
#include "config.h"
#include "communication.h"
#include "monitoring.h"
#include "switching.h"
#include "storage.h"

communication comms;
switching the_switch(13);	//connect relay to pin A1
monitoring monitor(A0);

char inputCommand;


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

	comms.connectToServer();
	//Serial.println("connectToServer");
	//comms.sendData(9);
	//Serial.println("send");

	if (Serial.available()) {
		int inputCommand = Serial.read(); 
		Serial.println(inputCommand);
	}

	if (the_switch.state == 1) {
		the_switch.state = 0;
		digitalWrite(13, HIGH);
	}
	else {
		the_switch.state = 1;
		digitalWrite(13, LOW);
	}
	
	if (inputCommand == 49) {
		Serial.println("on");
		the_switch.setState(1);
		
	}
	if (inputCommand == 48) {
		Serial.println("off");
		the_switch.setState(0);
		
	}

	//Serial.print("The switch is ");
	//Serial.println(the_switch.getState());
	//Serial.print("The current power consumption is ");
	Serial.println(monitor.calculatePower());
	delay(1000);
}
