
#include "NodeStatus.h"


NodeStatus::NodeStatus(){
	
	ntime = new NodeTime();

	_gps_stat = GPS_NO_COMS;
	_gps_lat = NULL;
	_gps_lon = NULL;
	_gps_alt = NULL;
	_gps_sats = NULL;
	_gps_time = NULL;
	
	_node_voltage = NULL;
	_accel_x = NULL;
	_accel_y = NULL;
	_accel_z = NULL;
	
	_trigger_mask = 0b10000000;
	_triggers = 0b0;
	_trips = 0b0;
	_digital_mask = 0b0;
	
	_output_mask = 0b0;
	_outputs = 0b0;
	
	_forced_output_mask = 0b0;
	_forced_output = 0b0;
	
	_vd_ratio = float(VD_REF/VD_RESOLUTION)*(VD_RESISTOR_1 + VD_RESISTOR_2)/VD_RESISTOR_2;
}


void NodeStatus::setGpsStat(int32_t gps_stat){
	_gps_stat = gps_stat;
}
int32_t NodeStatus::getGpsStat(){
	return _gps_stat;
}

void NodeStatus::setGpsLatInt(int32_t gps_lat){
	_gps_lat = gps_lat;
}
int32_t NodeStatus::getGpsLatInt(){
	return _gps_lat;
}

void NodeStatus::setGpsLonInt(int32_t gps_lon){
	_gps_lon = gps_lon;
}
int32_t NodeStatus::getGpsLonInt(){
	return _gps_lon;
}

void NodeStatus::setGpsAltInt(int32_t gps_alt){
	_gps_alt = gps_alt;
}
int32_t NodeStatus::getGpsAltInt(){
	return _gps_alt;
}

void NodeStatus::setGpsSats(int32_t gps_sats){
	_gps_sats =gps_sats;
}
int32_t NodeStatus::getGpsSats(){
	return _gps_sats;
}

void NodeStatus::setGpsTime(int32_t gps_time){
	_gps_time = gps_time;
}
int32_t NodeStatus::getGpsTime(){
	return _gps_time;
}

void NodeStatus::setNodeVoltageRaw(int node_voltage){
	_node_voltage = node_voltage;
}
int NodeStatus::getNodeVoltageRaw(){
	return _node_voltage;
}
float NodeStatus::getNodeVoltageFloat(){
	return _node_voltage*_vd_ratio;
}
int32_t NodeStatus::getNodeVoltageInt(){
	return int(100*getNodeVoltageFloat());
}

void NodeStatus::setAccelX(int32_t accel_x){
	_accel_x = accel_x;
}
int32_t NodeStatus::getAccelX(){
	return _accel_x;
}

void NodeStatus::setAccelY(int32_t accel_y){
	_accel_y = accel_y;
}
int32_t NodeStatus::getAccelY(){
	return _accel_y;
}
void NodeStatus::setAccelZ(int32_t accel_z){
	_accel_z = accel_z;
}
int32_t NodeStatus::getAccelZ(){
	return _accel_z;
}

void NodeStatus::setTriggers(byte triggers){
	_triggers = triggers;
}
byte NodeStatus::getTriggers(){
	return _triggers;
}
void NodeStatus::setTriggersOn(byte t_mask){
	setTriggers(getTriggers() | t_mask);
	setTripsOn(t_mask);
}
void NodeStatus::setTriggersOff(byte t_mask){
	setTriggers(getTriggers() & ~t_mask);
}

void NodeStatus::setTrips(byte trips){
	_trips = trips;
}
byte NodeStatus::getTrips(){
	return _trips;
}
void NodeStatus::setTripsOn(byte t_mask){
	setTrips(getTrips() | t_mask);
}
void NodeStatus::setTripsOff(byte t_mask){
	setTrips(getTrips() & ~t_mask);
}
void NodeStatus::clearTrips(){
	setTrips(0b0);
}

void NodeStatus::setTriggerMask(byte t_mask){
	_trigger_mask = t_mask;
}
byte NodeStatus::getTriggerMask(){
	return _trigger_mask;
}
void NodeStatus::addTriggerMask(byte t_mask){
	setTriggerMask(getTriggerMask() | t_mask);
}
void NodeStatus::removeTriggerMask(byte t_mask){
	setTriggerMask(getTriggerMask() & ~t_mask);
}


void NodeStatus::setTamperOn(){
	setTriggersOn(0b10000000);
}
void NodeStatus::setTamperOff(){
	setTriggersOff(0b10000000);		
}

bool NodeStatus::getTamper(){
	if(getTriggers() & 0b10000000){
		return true;
	}
	else{
		return false;
	}
}


void NodeStatus::setOutputs(byte outputs){
	_outputs = outputs;
}
byte NodeStatus::getOutputs(){
	return _outputs;
}
void NodeStatus::setOutputsOn(byte o_mask){
	setOutputs(getOutputs() | o_mask);
}
void NodeStatus::setOutputsOff(byte o_mask){
	setOutputs(getOutputs() & ~o_mask);
}

void NodeStatus::setOutputMask(byte o_mask){
	_output_mask = o_mask;
}
byte NodeStatus::getOutputMask(){
	return _output_mask;
}
void NodeStatus::addOutputMask(byte o_mask){
	setOutputMask(getOutputMask() | o_mask);
}
void NodeStatus::removeOutputMask(byte o_mask){
	setOutputMask(getOutputMask() & ~o_mask);
}



void NodeStatus::setDigitalMask(byte digital_mask){
	_digital_mask = digital_mask;
}
byte NodeStatus::getDigitalMask(){
	return _digital_mask;
}

void NodeStatus::setForcedOutputMask(byte forced_output_mask){
	_forced_output_mask = forced_output_mask;
}
byte NodeStatus::getForcedOutputMask(){
	return _forced_output_mask;
}
		
void NodeStatus::setForcedOutput(byte forced_output){
	_forced_output = forced_output;
}
byte NodeStatus::getForcedOutput(){
	return _forced_output;
}

