
#include "config.h"
#include "communication.h"
#include "Arduino.h"
#include <string.h>


communication::communication() : esp8266(10, 11)
{
	
	esp8266.begin(115200);
	esp8266.println("AT+CWMODE_CUR=3");
}

int communication::connectToNetwork()
{
	esp8266.println("AT+CWMODE_CUR=3");
	//delay(100);
	esp8266.println("AT+CWJAP_CUR=\"OPTUS_63B07D\",\"entervatic65647\"");
	//delay(100);
	/*for (int i = 0; i < 1000; i++) {
		if (esp8266.available()) { Serial.write(esp8266.read()); }
		delay(1);
	}*/
	return 1;
}

int communication::connectToServer()
{
	esp8266.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80");
  //Serial.println("connectToServer");
	
	return 1;
}

int communication::sendData(int val)
{
	esp8266.println("AT+CIPSEND=53");
	//delay(50);
	esp8266.println("GET /update?api_key=54EP6VAFSMRGSPCG&field1=90 \r\n");
	if (esp8266.available()) { Serial.write(esp8266.read()); }
  //Serial.println("send");

	return 1;
}
