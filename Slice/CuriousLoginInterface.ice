#ifndef curious_login_interface_ice
#define curious_login_interface_ice

module Curious
{
	interface LoginInterface
	{
		["amd"] int quickLogin(string sMachineInfo, out int iResult);

		["amd"] int login(string sID, string sPassword, string sDomain, out int iResult);
	}	
};

#endif
