

#ifndef AnalogAccel_h
#define AnalogAccel_h

#include "Arduino.h"
#include "ExCommon.h"



class AnalogAccel
{
	public:
		AnalogAccel();
		void init();
		void update(NodeStatus *nstat);
		
		
	private:
		int _accel[3][ACCEL_BUFF_SIZE];
		float _accel_avg[3];
		int _accel_sample;
		int _accel_diff;
		
		String _axis;
		char _analog_pin[3];
		int _index;
		unsigned long _last_time;
		
		bool _tamper;

		
};


	
	
#endif