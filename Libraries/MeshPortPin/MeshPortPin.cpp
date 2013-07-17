
#include "MeshPortPin.h"




MeshPortPin::MeshPortPin(int pin){
	setPin(pin);

}


void MeshPortPin::setPin(int pin){
	_pin = pin;
}

int MeshPortPin::getPin(){
	return _pin;
}
