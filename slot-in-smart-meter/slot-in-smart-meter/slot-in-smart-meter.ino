
#include "config.h"
#include "communication.h"
#include "monitoring.h"
#include "switching.h"



void setup() {
  Serial.begin(9600);
  Serial.print("hi");
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
