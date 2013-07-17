/*	GPS.cpp

	GPS Driver Library
	Adapted from GPS MTK library posted to DIYDrones.com
	Author: Exponent/TechDev/Alexander Naiman

*/

#include "MTK_GPS.h"

// Constructor
MTK_GPS::MTK_GPS(uint8_t iPin, uint8_t oPin) {
	gpsPort = new SoftwareSerial(iPin, oPin);
	_setBaud = true;
}


// Initialize GPS module
void MTK_GPS::init(void) {
	gpsPort->begin(38400);
	gpsPort->print(MTK_SET_BINARY);
	gpsPort->print(MTK_OUTPUT_4HZ);
	gpsPort->print(MTK_BAUD_RATE_9600);
	gpsPort->end();
	gpsPort->begin(9600);
}

void MTK_GPS::initBinary(void) {
	
	gpsPort->print(MTK_SET_BINARY);
	gpsPort->print(MTK_OUTPUT_4HZ);
}

void MTK_GPS::initBaud(void){
	gpsPort->end();
	gpsPort->begin(38400);
	gpsPort->print(MTK_BAUD_RATE_9600);
	gpsPort->end();
	gpsPort->begin(9600);
}

void MTK_GPS::repair(void){
	gpsPort->end();
	init();
	/*
	if(_setBaud){
		initBaud();
		_setBaud = false;
	}
	else{
		initBinary();
		_setBaud = true;
	}
	*/
}

// Read and parse GPS data from module
bool MTK_GPS::read(void) {

	uint8_t 	data;
	int 		numc;
	bool		parsed = false;
	
	_step = 0;
	numc = gpsPort->available();
	for (int i = 0; i < numc; i++) {
		data = gpsPort->read();
    
restart:
		switch(_step) {

			// Message preamble, class, ID detection
			//
			// If we fail to match any of the expected bytes, we
			// reset the state machine and re-consider the failed
			// byte as the first byte of the preamble.  This
			// improves our chances of recovering from a mismatch
			// and makes it less likely that we will be fooled by
			// the preamble appearing as data in some other message.
			//
		case 0:		
			if (data == PREAMBLE1_V16) {
                _mtk_revision     = MTK_GPS_REVISION_V16;
                _step++;
            } 
			else if (data == PREAMBLE1_V19) {
                _mtk_revision     = MTK_GPS_REVISION_V19;
                _step++;
            }
			break;
		case 1:
			if (data == PREAMBLE2) {
                _step++;
            } 
			else {
                _step = 0;
                goto restart;
            }
            break;

		case 2:
			if (sizeof(_buffer) == data) {
				_step++;
				_ck_b = _ck_a = data;				// reset the checksum accumulators
				_payload_counter = 0;
			} else {
				_step = 0;							// reset and wait for a message of the right class
				goto restart;
			}
			break;

			// Receive message data
			//
		case 3:
			_buffer.bytes[_payload_counter++] = data;
			_ck_b += (_ck_a += data);
			if (_payload_counter == sizeof(_buffer)){
				_step++;
			}
			break;

			// Checksum and message processing
			//
		case 4:
			_step++;
			if (_ck_a != data) {
				_step = 0;
				goto restart;
			}
			break;
		case 5:
			_step = 0;
			if (_ck_b != data) {
				goto restart;;
			}
			
			if (_mtk_revision == MTK_GPS_REVISION_V16) {
                latitude    = _buffer.msg.latitude  * 10;  // V16, V17,V18 doc says *10e7 but device says otherwise
                longitude   = _buffer.msg.longitude * 10;  // V16, V17,V18 doc says *10e7 but device says otherwise
            } 
			else {
                latitude    = _buffer.msg.latitude;
                longitude   = _buffer.msg.longitude;
            }
			altitude		= _buffer.msg.altitude;
			ground_speed	= _buffer.msg.ground_speed;
			ground_course	= _buffer.msg.ground_course;
			num_sats		= _buffer.msg.satellites;
			hdop			= _buffer.msg.hdop;
			date			= _buffer.msg.utc_date;
			fix				= _buffer.msg.fix_type;

			// time from gps is UTC, but convert here to msToD
			int32_t time_utc= _buffer.msg.utc_time;
            int32_t temp    = (time_utc/10000000);
            time_utc       -= temp*10000000;
            time            = temp * 3600000;
            temp            = (time_utc/100000);
            time_utc       -= temp*100000;
            time           += temp * 60000 + time_utc;
			
            parsed          = true;


		}
	}
    return parsed;    
}
