#include "CuriousGateInterfaceI.h"

namespace Curious
{
	taf::TC_ThreadQueue<TransferRequestPtr> g_transferQueue;
	
	void GateInterfaceI::transfer_async(const AMD_GateInterface_transferPtr* callback,
		                                const Message_S& message,
		                                const Ice::Current& current)
	{

	}
}

