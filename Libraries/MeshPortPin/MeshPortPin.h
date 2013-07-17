#ifndef MeshPortPin_h
#define MeshPortPin_h

#include "Arduino.h"
#include "ExCommon.h"
#include "MeshPort.h"



class MeshPortPin : public MeshPort
{
	public:
		MeshPortPin(int pin);

		
	protected:
		void	setPin(int pin);
		int 	getPin();
		int		_pin;

		
};


	
	
#endif