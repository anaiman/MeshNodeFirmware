#ifndef MeshPortPinDigitalOut_h
#define MeshPortPinDigitalOut_h

#include "Arduino.h"
#include "ExCommon.h"
#include "MeshPort.h"
#include "MeshPortPin.h"



class MeshPortPinDigitalOut : public MeshPortPin
{
	public:
						MeshPortPinDigitalOut(int pin, byte local_auto_io_map);
		virtual void 	updateOutputs(NodeStatus *nstat);
		
		
	protected:
		virtual void	setOutputOn();	
		virtual void	setOutputOff();
		unsigned long	_output_timer;
		
		
};


	
	
#endif