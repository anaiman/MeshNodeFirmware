

#ifndef ExXbee_h
#define ExXbee_h

#include "Arduino.h"

#include "ExCommon.h"
#include "XBee.h"

class ExXbee
{
	public:
		ExXbee(int baud);
		void init();
		void send(byte payload[], int payloadSize);
		void recieve(NodeStatus *nstat);
	private:
		int _baud;
		XBee *_xbee;
		ZBRxResponse _rx;
		
		union{
			HeartbeatMsg_t msg;
			uint8_t	bytes[];
		} _heartbeat;
		
		
};
	
	
#endif