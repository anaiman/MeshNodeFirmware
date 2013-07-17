
#include "ExXbee.h"

ExXbee::ExXbee(int baud)
{
	_baud = baud;
	_xbee = new XBee(XBEE_RX_PIN,XBEE_TX_PIN);
	_rx = ZBRxResponse();
}

void ExXbee::init(){
	pinMode(XBEE_RTS_PIN,OUTPUT);
	digitalWrite(XBEE_RTS_PIN,LOW);
	_xbee->begin(_baud);
}

void ExXbee::send(byte payload[], int payloadSize){
	XBeeAddress64 addr64 = XBeeAddress64(XNC_SH, XNC_SL);
	ZBTxRequest zbTx = ZBTxRequest(addr64, payload, payloadSize);
	ZBTxStatusResponse txStatus = ZBTxStatusResponse();
	
	_xbee->send(zbTx);

}

void ExXbee::recieve(NodeStatus *nstat){

	_xbee->readPacket();
    
    if (_xbee->getResponse().isAvailable()) {
      // got something
      
		if (_xbee->getResponse().getApiId() == ZB_RX_RESPONSE) {
			// got a zb rx packet
        
			// now fill our zb rx class
			_xbee->getResponse().getZBRxResponse(_rx);
		}
	
		for(int i = 0; i<_rx.getDataLength(); i++){
			_heartbeat.bytes[i]=_rx.getData(i);
		}
	}
	

}