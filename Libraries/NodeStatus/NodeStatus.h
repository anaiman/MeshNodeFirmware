

#ifndef NodeStatus_h
#define NodeStatus_h

#include "Arduino.h"
#include "NodeTime.h"
#include "ExCommon.h"




class NodeStatus
{
	public:
		NodeStatus();
		
		NodeTime *ntime;
		
		void 	setGpsStat(int32_t gps_stat);
		int32_t	getGpsStat();

		void	setGpsLatInt(int32_t gps_lat);
		int32_t getGpsLatInt();

		void 	setGpsLonInt(int32_t gps_lon);
		int32_t getGpsLonInt();

		void 	setGpsAltInt(int32_t gps_alt);
		int32_t getGpsAltInt();

		void 	setGpsSats(int32_t gps_sats);
		int32_t getGpsSats();

		void 	setGpsTime(int32_t gps_time);
		int32_t getGpsTime();

		void 	setNodeVoltageRaw(int node_voltage);
		int 	getNodeVoltageRaw();
		float	getNodeVoltageFloat();
		int32_t	getNodeVoltageInt();

		void 	setAccelX(int32_t accel_x);
		int32_t getAccelX();

		void 	setAccelY(int32_t accel_y);
		int32_t getAccelY();
		
		void 	setAccelZ(int32_t accel_z);
		int32_t getAccelZ();

		void 	setTriggers(byte triggers);
		byte    getTriggers();
		void 	setTriggersOn(byte t_mask);
		void 	setTriggersOff(byte t_mask);
		
		void 	setTrips(byte triggers);
		byte    getTrips();
		void 	setTripsOn(byte t_mask);
		void 	setTripsOff(byte t_mask);
		void 	clearTrips();
		
		void 	setTriggerMask(byte t_mask);
		byte    getTriggerMask();
		void 	addTriggerMask(byte t_mask);
		void 	removeTriggerMask(byte t_mask);
		
		void 	setTamperOn(); //MSB of the triggers byte
		void 	setTamperOff();
		bool 	getTamper();
		
		void 	setOutputs(byte output);
		byte 	getOutputs();
		void 	setOutputsOn(byte o_mask);
		void 	setOutputsOff(byte o_mask);
		
		void 	setOutputMask(byte o_mask);
		byte    getOutputMask();
		void 	addOutputMask(byte o_mask);
		void 	removeOutputMask(byte o_mask);
		
		void 	setDigitalMask(byte digital_mask);
		byte 	getDigitalMask();
		
		void	setForcedOutputMask(byte forced_output_mask);
		byte	getForcedOutputMask();
		
		void	setForcedOutput(byte forced_output_mask);
		byte	getForcedOutput();

		
		
		
	private:
		int32_t		_gps_stat;
		int32_t	 	_gps_lat;
		int32_t 	_gps_lon;
		int32_t  	_gps_alt;
		int32_t		_gps_sats;
		int32_t		_gps_time;

		int 		_node_voltage;
		int32_t 	_accel_x;
		int32_t 	_accel_y;
		int32_t 	_accel_z;
		
		byte		_trigger_mask;
		byte 	 	_triggers;
		byte		_trips;
		byte		_digital_mask; //Defines when a DIO pin is triggered: 1 means triggered when input is HIGH
		
		byte 	 	_output_mask;
		byte 	 	_outputs;
		
		byte		_forced_output_mask; 	//Which outputs are being forced 0=Auto, 1=Forced
		byte		_forced_output;			//Forced output stated 0=On, 1=Off

		float		_vd_ratio;
		
		
		
		
		
		

		
		
};


	
	
#endif