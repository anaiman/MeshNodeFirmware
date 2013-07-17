#ifndef NodeTime_h
#define NodeTime_h

#include "Arduino.h"
//#include "ExCommon.h"



class NodeTime
{
	public:
		NodeTime();
		unsigned long	getElapsedSince(unsigned long last_time);
		unsigned long	getSystemTime();
		
	protected:
	
		
		
};


	
	
#endif