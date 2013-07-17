
#include "MeshPort.h"


byte MeshPort::getTriggerMask(){
	return _trigger_mask;
}
void MeshPort::setTriggerMask(byte b){
	_trigger_mask = b;
}



void MeshPort::setOutputMask(byte b){
	 _output_mask = b ;
}
byte MeshPort::getOutputMask(){
	return _output_mask;
}


void MeshPort::setLocalAutoIoMap(byte b){
	_local_auto_io_map = b;
}

byte MeshPort::getLocalAutoIoMap(){
	return _local_auto_io_map;
}

void MeshPort::setNetAutoIoMap(byte b){
	_net_auto_io_map = b;
}

byte MeshPort::getNetAutoIoMap(){
	return _net_auto_io_map;
}

void MeshPort::setOutputTimerByte(byte otimer){
	_output_timer = otimer;
}
byte MeshPort::getOutputTimerByte(){
	return _output_timer;
}

void MeshPort::setOutputTimerLong(unsigned long otimer){
	otimer = otimer/5000;
	if(otimer > 254){
		otimer = 254;
	}
	setOutputTimerByte(byte(otimer));
}

unsigned long MeshPort::getOutputTimerLong(){
	unsigned long  timer_long =  long(getOutputTimerByte());
	return timer_long*5000;
}

void MeshPort::setTimeLastTriggered(unsigned long t_time){
	_time_last_triggered = t_time;
}

unsigned long MeshPort::getTimeLastTriggered(){
	return _time_last_triggered;
}



byte MeshPort::getBitMaskForPin(int pin){
	if (pin == MEGA_RX){
		return 0b1;
	}
	else if (pin == MEGA_TX){
		return 0b10;
	}
	else if (pin == MEGA_MOSI){
		return 0b100;
	}
	else if (pin == MEGA_MISO){
		return 0b1000;
	}
	else if (pin == MEGA_SCK){
		return 0b10000;
	}
	else if (pin == MEGA_SDA){
		return 0b100000;
	}
	else if (pin == MEGA_SCL){
		return 0b1000000;
	}

}