#include "CuriousMasterInterfaceI.h"

namespace Curious
{
	//global register queue
	taf::TC_ThreadQueue<RegisterRequestPtr> g_registerQueue;

	void CuriousMasterInterfaceI::register_async(const AMD_Master_registerPtr& callback,
		                                         const std::string& sServerIP,
		                                         const Ice::Current& current)
	{
		g_registerQueue.push_back(new RegisterRequest(callback, sServerIP));
	}

}
