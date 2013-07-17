
#include "ExSerial.h"

ExSerial::ExSerial(int baud)
{
	_baud = baud;
	Serial.begin(_baud);
}

void ExSerial::init(){
	Serial.begin(_baud);
}

void ExSerial::send(byte payload[], int payloadSize){
	Serial.write(payload,payloadSize);
	
	/*
	for(int n=0;n<payloadSize;n++){
		Serial.print(payload[n],HEX);
	}
	Serial.println();
	*/

}
