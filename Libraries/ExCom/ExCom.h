

#ifndef ExCom_h
#define ExCom_h

#include "Arduino.h"

#include "ExCommon.h"
#include "ExSerial.h"
#include "ExXbee.h"

class ExCom
{
	public:
		ExCom();
		void init();
		void send(byte payload[], int payloadSize);
		void recieve(NodeStatus *nstat);
	private:
		#ifdef SERIALCOM 
		ExSerial *_link;
		#endif
		
		#ifdef XBEECOM   
		ExXbee *_link;
		#endif
		
		
};
	
	
#endif