#ifndef curious_gate_interface_ice
#define curious_gate_interface_ice

module Curious
{
	interface GateInterface
	{
		["amd"] int tranfer(Message_S message);
	};	
};

#endif