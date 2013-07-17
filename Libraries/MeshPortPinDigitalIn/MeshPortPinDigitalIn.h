#ifndef MeshPortPinDigitalIn_h
#define MeshPortPinDigitalIn_h

#include "Arduino.h"
#include "ExCommon.h"
#include "MeshPort.h"
#include "MeshPortPin.h"



class MeshPortPinDigitalIn : public MeshPortPin
{
	public:
						MeshPortPinDigitalIn(int pin);
		virtual void 	updateInputs(NodeStatus *nstat);
		
	protected:
		
		
};


	
	
#endif