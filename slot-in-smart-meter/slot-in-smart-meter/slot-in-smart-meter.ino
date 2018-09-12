
#include "config.h"
#include "communication.h"
#include "monitoring.h"
#include "switching.h"
#include "storage.h"

//communication comms;
//switching the_switch(13);	//connect relay to pin A1
monitoring monitor(A0);

byte inputCommand;
int relayPin = 12;
unsigned long previousMillis = 0;
const long interval = 1000;


void setup() {
	Serial.begin(9600);
  //Serial.println("Hello");
	//comms.connectToNetwork();
	digitalWrite(relayPin, HIGH);
}



void loop() {
	/*
	every 1 seconds:
	monitor and log power
	read 
	
	*/
	unsigned long currentMillis = millis();

	if (currentMillis - previousMillis >= interval) {
		previousMillis = currentMillis;

		//comms.connectToServer();
		//comms.sendData(90);

    // print the instentanous power draw in watts to serial
    Serial.println(monitor.calculatePower());
    inputCommand = 0;
		//Set the state of the switch based on the command
		if (inputCommand == 49) {
			digitalWrite(relayPin, HIGH);

		}
		else if (inputCommand == 48) {
			digitalWrite(relayPin, LOW);

		}

		/*if (Serial.available()) {
			inputCommand = Serial.read();
			Serial.write(inputCommand);

			if (inputCommand == 49) {
				digitalWrite(relayPin, HIGH);

			}
			else if (inputCommand == 48) {
				digitalWrite(relayPin, LOW);

			}
		}*/
	}
}
