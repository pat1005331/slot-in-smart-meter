
#include "config.h"
#include "communication.h"


communication::communication() : esp8266(10, 11)
{
	
	esp8266.begin(115200);
	esp8266.println("AT+CWMODE_CUR=3");
}

int communication::connectToNetwork()
{
	esp8266.println("AT+CWJAP_CUR=\"OPTUS_63B07D\",\"entervatic65647\"");
  //Serial.println("connectToNetwork");
	return 1;
}

int communication::connectToServer()
{
	esp8266.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80");
  //Serial.println("connectToServer");
	
	return 1;
}

int communication::sendData()
{
	esp8266.println("AT+CIPSEND=52");
	esp8266.println("GET /update?api_key=54EP6VAFSMRGSPCG&field1=6 \r\n");
  //Serial.println("send");

	return 1;
}
