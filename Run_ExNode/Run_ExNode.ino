

#include "SoftwareSerial.h"

#include <inttypes.h>

#include <ExNode.h>
#include <ExCommon.h>
#include <NodeTime.h>
#include <NodeStatus.h>

#include <ExCom.h>
#include <ExSerial.h>
#include <AnalogAccel.h>


#include <ExXbee.h>
#include <XBee.h>

#include <ExGPS.h>
#include <MTK_GPS.h>

#include <MeshPort.h>
#include <MeshPortPin.h>
#include <MeshPortPinDigitalIn.h>
#include <MeshPortPinDigitalOut.h>
#include <MeshPortPinMakeBreak.h>


unsigned long previousMillisFastTimer = 0;
unsigned long previousMillisSlowTimer = 0;
unsigned long previousMillisCamTimer = 0;
unsigned long currentMillis = 0;
int fastTimer = 100;
int slowTimer = 1000;

int gpsEN = 4;

ExNode exNode = ExNode();

void setup(){
  Serial.begin(9600);
  
  
  pinMode(gpsEN, OUTPUT);
  digitalWrite(gpsEN, HIGH);
  
  exNode.initCOM();
  exNode.initGPS();
  exNode.initAccel();

}


void loop(){
  currentMillis = millis();

  
  if(currentMillis-previousMillisFastTimer > fastTimer){
    previousMillisFastTimer=currentMillis;
    exNode.updateFast();
    
    
  }

  if(currentMillis-previousMillisSlowTimer > slowTimer){
    previousMillisSlowTimer=currentMillis;
    exNode.updateSlow();
    DebugOut();
    
    
    
  }

}


void DebugOut(){
    Serial.print(exNode.nstat->ntime->getSystemTime());
    Serial.print(" L");
    Serial.print(exNode.nstat->getGpsLatInt());
    Serial.print(" l");
    Serial.print(exNode.nstat->getGpsLonInt());
    if(exNode.nstat->getTamper()){
      Serial.print(" t1");
    }
    else{
      Serial.print(" t0");
    }
    Serial.print(" T");
    Serial.print(exNode.nstat->getTriggers(),BIN);
    Serial.print(" O");
    Serial.print(exNode.nstat->getOutputs(),BIN);
    Serial.print(" V");
    Serial.print(exNode.nstat->getNodeVoltageFloat());
    Serial.println();
}


