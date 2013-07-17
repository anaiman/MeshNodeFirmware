
#include "ExGPS.h"

ExGPS::ExGPS()
{
	_gps = new MTK_GPS(GPS_RX_PIN,GPS_TX_PIN);
	_last_read_time = 0;


}

void ExGPS::init(){
	_gps->init();
	
}

void ExGPS::update(NodeStatus *nstat){
	if (_gps->read()) {
		_last_read_time = millis();
		
		if(_gps->fix == NO_FIX){
			nstat->setGpsStat(GPS_NO_LOCK);
			nstat->setGpsLatInt( 444 );
			nstat->setGpsLonInt( 444 );
			nstat->setGpsAltInt( 444 );
		}
		else{
			nstat->setGpsStat(GPS_LOCK);
			nstat->setGpsLatInt( _gps->latitude);
			nstat->setGpsLonInt( _gps->longitude);
			nstat->setGpsAltInt( _gps->altitude);
		}

	}
	else{
		if (GPS_IDLE_TIME+_last_read_time<millis()){
			_last_read_time = millis();
			nstat->setGpsStat(GPS_NO_COMS);
			_gps->repair();
			
			nstat->setGpsLatInt( 555 );
			nstat->setGpsLonInt( 555 );
			nstat->setGpsAltInt( 555 );
			
			
			
		}

	}
	
}