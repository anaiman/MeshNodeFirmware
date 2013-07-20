

#ifndef ExNode_h
#define ExNode_h

#include "Arduino.h"

#include "ExCommon.h"

#include "AnalogAccel.h"
#include "ExCom.h"
#include "ExGPS.h"
#include "MeshPort.h"
#include "MeshPortPin.h"
#include "MeshPortPinDigitalIn.h"
#include "MeshPortPinMakeBreak.h"
#include "MeshPortPinDigitalOut.h"


class ExNode
{
	public:
		ExNode();
		void 	initGPS();
		void 	initCOM();
		void 	initAccel();
		void 	updateFast();
		void 	updateSlow();
		NodeStatus *nstat;
		
		
	private:
		
		ExCom *_coms;
		ExGPS *_gps;
		AnalogAccel *_accel;
		MeshPort *_io_port;
		MeshPort *_io_port2;
		MeshPort *_io_port3;
		MeshPort *_io_port4;
		MeshPort *_io_port5;
		void sendHeartbeat();
		
		union{
			HeartbeatMsg_t msg;
			uint8_t	bytes[];
		} _heartbeat;
		
		
};


	
	
#endif