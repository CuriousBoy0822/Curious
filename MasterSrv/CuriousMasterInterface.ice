#ifndef curious_master_interface_ice
#define curious_master_interface_ice

module Curious
{
	interface MasterInterface
	{
		["amd"] int register(string sServerIP, out string sNextServerIP);
	};
};

#endif
