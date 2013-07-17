
#include "MeshPortPinDigitalIn.h"




MeshPortPinDigitalIn::MeshPortPinDigitalIn(int pin) : MeshPortPin(pin){
	setTriggerMask(getBitMaskForPin(getPin()));
	pinMode(getPin(), INPUT);
	
	

}

void MeshPortPinDigitalIn::updateInputs(NodeStatus *nstat){
	if (digitalRead(getPin())){
		if(nstat->getDigitalMask() & getTriggerMask()){
			nstat->setTriggersOn(getTriggerMask());
		}
		else{
			nstat->setTriggersOff(getTriggerMask());
		}
	}
	else{
		if(nstat->getDigitalMask() & getTriggerMask()){
			nstat->setTriggersOff(getTriggerMask());
		}
		else{
			nstat->setTriggersOn(getTriggerMask());
		}
	}
}