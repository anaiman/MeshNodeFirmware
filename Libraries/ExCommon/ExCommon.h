
#ifndef ExCommon
#define ExCommon

///Includes
#include "NodeStatus.h"


///Select Board Model
#define NODE_VERSION BETA
//Node Versions
#define ALPHA 0
#define BETA 1


///ATMega Pin Def
#define MEGA_RX 	0
#define MEGA_TX 	1
#define MEGA_MOSI 	11  
#define MEGA_MISO	12
#define MEGA_SCK	13
#define MEGA_SDA	A4
#define MEGA_SCL	A5

////Load Pinouts
#if NODE_VERSION == ALPHA
	//Port Pin Names
		#define PORT_IO_0 	MEGA_RX
		#define PORT_IO_1 	MEGA_TX
		#define PORT_IO_2 	MEGA_MOSI
		#define PORT_IO_3 	MEGA_MISO
		#define PORT_IO_4 	MEGA_SCK
		#define PORT_IO_5 	MEGA_SDA
		#define PORT_IO_6 	MEGA_SCL
		#define PORT_IO_7 	A1
	//XBee
		#define XBEE_RX_PIN 9
		#define XBEE_TX_PIN 8
		#define XBEE_RTS_PIN 7
	//GPS
		#define GPS_RX_PIN 2		
		#define GPS_TX_PIN 3
		#define GPS_EN_PIN 4
	//Accelerometer
		#define ACCEL_X_PIN A0
		#define ACCEL_Y_PIN A2
		#define ACCEL_Z_PIN A3
		#define ACCEL_POWER_PIN 10
	//Voltage Input
		#define VD_ADC_PIN A7
		
#elif NODE_VERSION == BETA
	//Port Pin Names
		#define PORT_IO_0 	MEGA_RX
		#define PORT_IO_1 	MEGA_TX
		#define PORT_IO_2 	MEGA_MOSI
		#define PORT_IO_3 	MEGA_MISO
		#define PORT_IO_4 	MEGA_SCK
		#define PORT_IO_5 	MEGA_SDA
		#define PORT_IO_6 	MEGA_SCL
		#define PORT_IO_7 	A1
	//XBee
		#define XBEE_RX_PIN 8
		#define XBEE_TX_PIN 9
		#define XBEE_RTS_PIN 7
	//GPS
		#define GPS_RX_PIN 2		
		#define GPS_TX_PIN 3
		#define GPS_EN_PIN 4
	//Accelerometer
		#define ACCEL_X_PIN A0
		#define ACCEL_Y_PIN A2
		#define ACCEL_Z_PIN A3
		#define ACCEL_POWER_PIN 10
	//Voltage Input
		#define VD_ADC_PIN A7
		
#endif







///Voltage Divider
#define VD_RESISTOR_1 10
#define VD_RESISTOR_2 1
#define VD_REF 3.3
#define VD_RESOLUTION 1023


///Comm Config
//#define SERIALCOM
#define XBEECOM
#define COM_LINK_BAUD 9600
//Message types
#define MSG_HEARTBEAT 0

///GPS Config
#define GPS_IDLE_TIME 1200
//MTK_GPS
#define PREAMBLE1_V16 0xd0
#define PREAMBLE1_V19 0xd1
#define PREAMBLE2 0xdd
#define MTK_GPS_REVISION_V16  16
#define MTK_GPS_REVISION_V19  19
#define MTK_SET_BINARY	"$PGCMD,16,0,0,0,0,0*6A\r\n"
#define MTK_OUTPUT_1HZ	"$PMTK220,1000*1F\r\n"
#define MTK_OUTPUT_2HZ	"$PMTK220,500*2B\r\n"
#define MTK_OUTPUT_4HZ	"$PMTK220,250*29\r\n"
#define MTK_OTUPUT_5HZ	"$PMTK220,200*2C\r\n"
#define MTK_OUTPUT_10HZ	"$PMTK220,100*2F\r\n"
#define MTK_BAUD_RATE_38400 "$PMTK251,38400*27\r\n"
#define MTK_BAUD_RATE_9600 "$PMTK251,9600*17\r\n"
#define MTK_BAUD_RATE_4800 "$PMTK251,4800*14\r\n"

///Xbee Config
#define XBEE_COOR_API 0
#define XBEE_ROUT_API 1
// Coornidator node
#define XNC_SH 0
#define XNC_SL 0
#define XNC_ID 149

////List of xbee's
//XN001 COOR API
#define XN001_VR XBEE_COOR_API
#define XN001_SH 0x007D33A2
#define XN001_SL 0x40861133
#define XN001_BD 9600

//XN002 ROUT API
#define XN002_VR XBEE_ROUT_API
#define XN002_SH 0x007D33A2
#define XN002_SL 0x40861677
#define XN002_BD 9600

//XN003 ROUT API
#define XN003_VR XBEE_ROUT_API
#define XN003_SH 0x007D33A2
#define XN003_SL 0x40980C59
#define XN003_BD 9600

//XN004 ROUT API
#define XN004_VR XBEE_ROUT_API
#define XN004_SH 0x007D33A2
#define XN004_SL 0x40980C87
#define XN004_BD 9600




///Defines
#define OFF	0
#define ON	1
#define TRIG_MOTION 1
#define TRIG_TAMPER 2

#define ULONG_ROLLOVER 4294967295


//GPS Status
#define GPS_NO_COMS 0
#define GPS_NO_LOCK 1
#define GPS_LOCK	2
//GPS MTK Fix
#define NO_FIX	1
#define	FIX_2D	2
#define FIX_3D	3
#define FIX_2D_SBAS 6
#define FIX_3D_SBAS 7


///ACCEL
#define ACCEL_BUFF_SIZE 10
#define ACCEL_THRESH 100
#define TAMPER_WAIT_TIMER 3000



//Common data types
#include <inttypes.h>

///User Struckts
struct HeartbeatMsg_t {
	int32_t lat;
	int32_t lon;
	int32_t alt;
	int32_t voltage;
	byte trigger_mask;
	byte triggers;
	byte trips;
	byte output_mask;
	byte outputs;
	
};





#endif