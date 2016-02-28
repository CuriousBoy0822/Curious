#ifndef curious_message_ice
#define curious_message_ice

module Curious
{
	struct Message_S
	{
		string sFrom;
		string sTo;
		string sTime;
		string sMessage;
		int    iTransferCount;
	};	
};

#endif
