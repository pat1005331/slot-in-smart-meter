
#include "config.h"
#include "communication.h"
#include "monitoring.h"
#include "switching.h"

communication comms;
//monitoring monitoring(A0);
//switching switching(4);

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
