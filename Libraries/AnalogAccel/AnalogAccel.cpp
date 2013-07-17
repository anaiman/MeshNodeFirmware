
#include "AnalogAccel.h"


AnalogAccel::AnalogAccel()
{
	_analog_pin[0] = ACCEL_X_PIN;
	_analog_pin[1] = ACCEL_Y_PIN;
	_analog_pin[2] = ACCEL_Z_PIN;
	_index = 0;
	
	_axis ="xyz";

}



void AnalogAccel::init(){
	pinMode(ACCEL_POWER_PIN,OUTPUT);
	digitalWrite(ACCEL_POWER_PIN,HIGH);
	
		_accel_avg[0] = analogRead(ACCEL_X_PIN);
		_accel_avg[1] = analogRead(ACCEL_Y_PIN);
		_accel_avg[2] = analogRead(ACCEL_Z_PIN);
	
	for(int n = 0 ; n < 3; n++){
		for(int i = 0 ; i < ACCEL_BUFF_SIZE; i++){
		  _accel[n][i] = _accel_avg[n];
		}
	}

}

void AnalogAccel::update(NodeStatus *nstat){
	_tamper = false;
	 for(int n = 0 ; n < 3; n++){
		_accel_sample = analogRead(_analog_pin[n]);
		_accel_diff = _accel_avg[n]-_accel_sample;
		
		if ( _accel_diff*_accel_diff > ACCEL_THRESH){
		  _tamper = true;
		}
		
		_accel_avg[n] = (_accel_avg[n]*ACCEL_BUFF_SIZE - _accel[n][_index] + _accel_sample)/ACCEL_BUFF_SIZE;
		_accel[n][_index] = _accel_sample;
		
		// Serial.print(_axis[n]);
		// Serial.print(": ");
		// for(int i = 0 ; i < ACCEL_BUFF_SIZE; i++){
		  // Serial.print(_accel[n][i]);
		  // Serial.print(" ");
		// }
		// Serial.print("avg:");
		// Serial.print(_accel_avg[n]);
		// Serial.print(" sample:");
		// Serial.print(_accel_sample);
		// Serial.println(" ");
		
		
	}	
	
	// Serial.print(_index);
	// Serial.print(" ");
	// Serial.println(_tamper);
	
	_index++;
	if(_index == ACCEL_BUFF_SIZE){
		_index = 0;
	}
	  
	if(_tamper){
		//Serial.println("Tamper");
		nstat->setTamperOn();
	}
	else{
		nstat->setTamperOff();
	}
}