
#include "config.h"
#include "communication.h"

#include <string.h>


communication::communication() : esp8266(10, 11)
{
	
	esp8266.begin(115200);
	esp8266.println("AT+CWMODE_CUR=3");
	while (esp8266.available()) { Serial.write(esp8266.read()); }
}

int communication::connectToNetwork()
{
	esp8266.println("AT+CWMODE_CUR=3");
	esp8266.println("AT+CWJAP_CUR=\"OPTUS_63B07D\",\"entervatic65647\"");
	//esp8266.println("AT+CWJAP_CUR=\"Paddy's phone\",\"rocketorienteering\"");
	while (esp8266.available()) { Serial.write(esp8266.read()); }
	Serial.println("connected");
	return 1;
}

int communication::connectToServer()
{
	esp8266.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80");
  //Serial.println("connectToServer");
	
	return 1;
}

byte communication::sendData(float val)
//see https://www.espressif.com/sites/default/files/documentation/4b-esp8266_at_command_examples_en.pdf
{
	byte reply = 49;

	esp8266.println("AT+CIPSEND=53");
	esp8266.println("GET /update?api_key=54EP6VAFSMRGSPCG&field1=90 \r\n");
	while (esp8266.available()) { Serial.write(esp8266.read()); }
	//esp8266.print(val);
	//esp8266.print(" \r\n");
	
	//some how get the reply command
	/*if (esp8266.available()) {
		for (int i = 0; i < 8; i++) {
			if (i == 8) {
				reply = esp8266.read();
			}
			else { esp8266.read(); }
		}
	}*/

	return reply;
}
