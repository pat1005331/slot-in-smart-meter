
#include "config.h"
#include "communication.h"

#include <string.h>


communication::communication() : esp8266(10, 11)
{
}

void communication::wait_for_ok()
{
  char prev = 0;
  Serial.println("Waiting for OK:");
  while (true) {
    char val = esp8266.read();
    if (val != -1) {
      Serial.write(val);
      if (val == 'K' && prev == 'O') {
        Serial.println("\nDone");
        return;
      }
      prev = val;
    }
  }
}

int communication::connectToNetwork()
{
  esp8266.begin(115200);

  esp8266.println("AT+UART_DEF=115200,8,1,0,3");
  wait_for_ok();
  
  esp8266.println("ATE0");
  wait_for_ok();
  
  Serial.println("Writing curmode");
  esp8266.println("AT+CWMODE_CUR=3");
  wait_for_ok();
  
	//esp8266.println("AT+CWJAP_CUR=\"OPTUS_63B07D\",\"entervatic65647\"");
	esp8266.println("AT+CWJAP_CUR=\"Paddy's phone\",\"rocketorienteering\"");
  wait_for_ok();
  Serial.println("connected");
	return 1;
}

int communication::connectToServer()
{
  Serial.println("Connecting to the server");
	esp8266.println("AT+CIPSTART=\"TCP\",\"requestbin.net\",80");
  wait_for_ok();


  Serial.println("Connected to server");
  esp8266.println("AT+CIPMODE=1");
  wait_for_ok();
  esp8266.println("AT+CIPSEND");
	
	return 1;
}

byte communication::sendData(float val)
//see https://www.espressif.com/sites/default/files/documentation/4b-esp8266_at_command_examples_en.pdf
{
	byte reply = 49;

  esp8266.print("GET /r/slr0kusm?v=");
  esp8266.print(val);
  esp8266.print(" HTTP/1.1\r\nHost: requestbin.net\r\n\r\n");
  Serial.println("Sent request");
	//esp8266.println("AT+CIPSEND=53");
 /*
	esp8266.println("POST /dapi/reading HTTP/1.1");
  esp8266.println("Host: ayers.pl");
  esp8266.println("Content-Type: application/json");
  esp8266.println("Content-Length: XX");
  esp8266.println("\r\n");
  esp8266.print("{\"device_id\": 1, \"consumption\":"); //31
  esp8266.print(val, 3); //5
  */
  

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
