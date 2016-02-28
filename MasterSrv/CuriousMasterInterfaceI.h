#ifndef curious_master_interfaceI_h
#define curious_master_interfaceI_h

#include <string>
#include "tc_thread_queue.h"
#include "CuriousRequest.h"
#include "CuriousMasterInterface.h"

using namespace taf;

namespace Curious
{
	class CuriousMasterInterfaceI : virtual public MasterInterface
	{
	public:
		virtual void register_async(const AMD_MasterInterface_registerPtr& callback, 
			                        const std::string& sServerIP, 
			                        const Ice::Current& = Ice::Current());
	};

	//global register queue
	extern taf::TC_ThreadQueue<RegisterRequestPtr> g_registerQueue;

};

#endif
