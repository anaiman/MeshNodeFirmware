

#ifndef ExGPS_h
#define ExGPS_h

#include "Arduino.h"

#include "ExCommon.h"
#include "MTK_GPS.h"

class ExGPS
{
	public:
		ExGPS();
		void update(NodeStatus *nstat);
		void init();
	private:
		MTK_GPS *_gps;
		unsigned long _last_read_time;

};
	
	
#endif