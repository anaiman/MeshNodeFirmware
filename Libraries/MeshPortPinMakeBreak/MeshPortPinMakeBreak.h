#ifndef MeshPortPinMakeBreak_h
#define MeshPortPinMakeBreak_h

#include "Arduino.h"
#include "ExCommon.h"
#include "MeshPort.h"
#include "MeshPortPin.h"
#include "MeshPortPinDigitalIn.h"




class  MeshPortPinMakeBreak : public MeshPortPinDigitalIn
{
	public:
						MeshPortPinMakeBreak(int pin);
		
	protected:
		
		
};


	
	
#endif