
#include "ExCom.h"

ExCom::ExCom()
{
	#ifdef SERIALCOM 
	_link = new ExSerial(COM_LINK_BAUD);
	#endif
	
	#ifdef	XBEECOM   
	_link = new ExXbee(COM_LINK_BAUD);
	#endif
}

void ExCom::init(){
	_link->init();
}

void ExCom::send(byte payload[], int payloadSize){

	
	_link->send(payload, payloadSize);

}

void ExCom::recieve(NodeStatus *nstat){
	
	_link->recieve(nstat);

}