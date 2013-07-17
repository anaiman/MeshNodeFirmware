
#include "MeshPortPinDigitalOut.h"




MeshPortPinDigitalOut::MeshPortPinDigitalOut(int pin, byte local_auto_io_map) : MeshPortPin(pin){
	setOutputMask(getBitMaskForPin(getPin()));
	setLocalAutoIoMap(local_auto_io_map);
	pinMode(getPin(), OUTPUT);
	setOutputTimerByte(0b1);
	
}

void MeshPortPinDigitalOut::updateOutputs(NodeStatus *nstat){
	if(nstat->getForcedOutputMask() & getOutputMask()){
		if(nstat->getForcedOutput() & getOutputMask()){
			nstat->setOutputsOn(getOutputMask());
		}
		else{
			nstat->setOutputsOff(getOutputMask());
		}
	}
	else{
		if (nstat->getTriggers() & getLocalAutoIoMap()){
			nstat->setOutputsOn(getOutputMask());
			setTimeLastTriggered(nstat->ntime->getSystemTime());
		}
		else if(nstat->ntime->getElapsedSince(getTimeLastTriggered()) < getOutputTimerLong()){
			nstat->setOutputsOn(getOutputMask());
		}
		else {
			nstat->setOutputsOff(getOutputMask());
		}
	}
	
	if (nstat->getOutputs() & getOutputMask()){
		setOutputOn();
	}
	else {
		setOutputOff();
	}

}

void MeshPortPinDigitalOut::setOutputOn(){
	digitalWrite(getPin(),HIGH);
}
void MeshPortPinDigitalOut::setOutputOff(){
	digitalWrite(getPin(),LOW);
}