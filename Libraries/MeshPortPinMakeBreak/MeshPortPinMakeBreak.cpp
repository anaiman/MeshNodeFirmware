
#include "MeshPortPinMakeBreak.h"




MeshPortPinMakeBreak::MeshPortPinMakeBreak(int pin) : MeshPortPinDigitalIn(pin){
	digitalWrite(getPin(), HIGH);
	
	

}
