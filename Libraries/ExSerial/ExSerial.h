

#ifndef ExSerial_h
#define ExSerial_h

#include "Arduino.h"
#include "ExCommon.h"

class ExSerial
{
	public:
		ExSerial(int baud);
		void init();
		void send(byte payload[], int payloadSize);
	private:
		int _baud;
};
	
	
#endif