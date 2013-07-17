/*	MTK_GPS.h

	MTK_GPS Driver Library
	Adapted from GPS MTK library posted to DIYDrones.com
	Author: Exponent/TechDev/Alexander Naiman

*/

#ifndef MTK_GPS_h
#define MTK_GPS_h

#include <Arduino.h>
#include <inttypes.h>
#include <SoftwareSerial.h>

#include "ExCommon.h"



class MTK_GPS
{
public:
	// Constructor
	MTK_GPS(uint8_t iPin, uint8_t oPin);
	
	// Public functions
    void	init(void);
	void	repair(void);
    bool	read(void);

    // Properties
    uint32_t	time;			///< GPS time (milliseconds from epoch)
    uint32_t	date;			///< GPS date (FORMAT TBD)
    int32_t	latitude;		///< latitude in degrees * 10,000,000
    int32_t	longitude;		///< longitude in degrees * 10,000,000
    int32_t	altitude;		///< altitude in cm
    int32_t	ground_speed;	///< ground speed in cm/sec
    int32_t	ground_course;	///< ground course in 100ths of a degree
    long	speed_3d;		///< 3D speed in cm/sec (not always available)
    uint16_t		hdop;			///< horizontal dilution of precision in cm
    uint8_t num_sats;		///< Number of visible satelites
	uint8_t	fix;			///< type of fix: 
	
private:
	
	void	initBinary(void);
	void	initBaud(void);
	bool	_setBaud;
	
	SoftwareSerial *gpsPort;

	struct diyd_mtk_msg {
    int32_t	latitude;
    int32_t	longitude;
    int32_t	altitude;
    int32_t	ground_speed;
    int32_t	ground_course;
    uint8_t	satellites;
    uint8_t	fix_type;
    uint32_t	utc_date;
    uint32_t	utc_time;
    uint16_t	hdop;
	};
	// Packet checksum accumulators
	uint8_t 	_ck_a;
	uint8_t 	_ck_b;
	// State machine state
	uint8_t 	_step;
	uint8_t		_payload_counter;
	uint8_t     _mtk_revision;

	// Receive buffer
	union {
		diyd_mtk_msg	msg;
		uint8_t		bytes[];
	} _buffer;
	
};

#endif
