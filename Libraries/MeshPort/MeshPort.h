#ifndef MeshPort_h
#define MeshPort_h

#include "Arduino.h"
#include "ExCommon.h"



class MeshPort
{
	public:
						MeshPort(){};
		virtual void 	init(){};
		virtual void 	updateInputs(NodeStatus *nstat){};
		virtual void 	updateOutputs(NodeStatus *nstat){};
		byte			getTriggerMask();
		byte			getOutputMask();
		
		void			setOutputTimerByte(byte otimer);
		void			setOutputTimerLong(unsigned long otimer);
		byte			getOutputTimerByte();
		unsigned long	getOutputTimerLong();
		
		
	protected:
		byte 			getBitMaskForPin(int pin);
		
		
		
	
		
		void			setTriggerMask(byte b);
		
		void			setOutputMask(byte b);
		
		
		
		void 			setLocalAutoIoMap(byte b);
		byte 			getLocalAutoIoMap();
		void 			setNetAutoIoMap(byte b);
		byte 			getNetAutoIoMap();
		
		
		virtual void	setOutputOn(){};	
		virtual void	setOutputOff(){};
		
		void			setTimeLastTriggered(unsigned long t_time);
		unsigned long	getTimeLastTriggered();
		
		
		
	
		byte			_trigger_mask;			// Defines Input Pins (rx for serial comm)
		byte			_trigger_state; 		// Current state of the input
		
		byte			_local_auto_io_map;		// Defines what local triggers switch a given output
		byte			_net_auto_io_map;		// Defines what network triggers switch a given output
		
		byte			_output_mask;			// Defines Output Pins (tx for serial comm)
		
		byte			_forced_output_mask; 	//Which outputs are being forced 0=Auto, 1=Forced
		byte			_forced_output;			//Forced output stated 0=On, 1=Off
		
		byte			_output_timer;     		//time the output remains on after last trigger (in 5s increments)
		unsigned long	_time_last_triggered;	//the last time the out put was turned on by a trigger
		
		

		
};


	
	
#endif