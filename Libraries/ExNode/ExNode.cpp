
#include "ExNode.h"


ExNode::ExNode()
{
	nstat = new NodeStatus();
	_coms = new ExCom();
	_gps = new ExGPS();
	_accel = new AnalogAccel();
	
	_io_port = new MeshPortPinMakeBreak(MEGA_MOSI);
	nstat->addTriggerMask(_io_port->getTriggerMask());
	
	_io_port2 = new MeshPortPinDigitalOut(MEGA_MISO, _io_port->getTriggerMask());
	nstat->addOutputMask(_io_port2->getOutputMask());
	
	_io_port3 = new MeshPortPinMakeBreak(MEGA_RX);
	nstat->addTriggerMask(_io_port3->getTriggerMask());
	
	_io_port4 = new MeshPortPinDigitalOut(MEGA_TX, _io_port3->getTriggerMask());
	nstat->addOutputMask(_io_port4->getOutputMask());
	
	_io_port5 = new MeshPortPinDigitalOut(MEGA_SCK, _io_port->getTriggerMask() | _io_port3->getTriggerMask());
	nstat->addOutputMask(_io_port5->getOutputMask());

}

void ExNode::initGPS(void){
	_gps->init();
}
void ExNode::initCOM(void){
	_coms->init();
}
void ExNode::initAccel(void){
	_accel->init();
}

void ExNode::updateFast(){
	_accel->update(nstat);
	_io_port->updateInputs(nstat);
	_io_port2->updateOutputs(nstat);
	
	_io_port3->updateInputs(nstat);
	_io_port4->updateOutputs(nstat);
	
	_io_port5->updateOutputs(nstat);
	//_coms->recieve(nstat);
}
	
void ExNode::updateSlow(){
	nstat->setNodeVoltageRaw(analogRead(VD_ADC_PIN));
	_gps->update(nstat);
	sendHeartbeat();

}

void ExNode::sendHeartbeat(){
	_heartbeat.msg.lat 			= nstat->getGpsLatInt();
	_heartbeat.msg.lon 			= nstat->getGpsLonInt();
	_heartbeat.msg.alt 			= nstat->getGpsAltInt();
	_heartbeat.msg.voltage 		= nstat->getNodeVoltageInt();
	_heartbeat.msg.trigger_mask = nstat->getTriggerMask();
	_heartbeat.msg.triggers 	= nstat->getTriggers();
	_heartbeat.msg.trips 		= nstat->getTrips();
	_heartbeat.msg.output_mask 	= nstat->getOutputMask();
	_heartbeat.msg.outputs 		= nstat->getOutputs();
	
	
	_coms->send(_heartbeat.bytes, sizeof(_heartbeat));
	/*
	Serial.print("H");
	for(int i = 0 ; i < sizeof(_heartbeat); i++){
		Serial.print(_heartbeat.bytes[i]);
	}
	*/
}
