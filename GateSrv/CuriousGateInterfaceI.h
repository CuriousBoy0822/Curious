#ifndef curious_gate_interfaceI_h
#define curious_gate_interfaceI_h

#include <string>
#include "tc_thread_queue.h"
#include "CuriousTransferRequest.h"
#include "CuriousGateInterface.h"

using namespace taf;

namespace Curious
{
	class GateInterfaceI : virtual public GateInterface
	{
	public:
		virtual void transfer_async(const AMD_GateInterface_transferPtr& callback,
			                        const Message_S& message,
			                        const Ice::Current& = Ice::Current());
	};

	extern taf::TC_ThreadQueue<TransferRequestPtr> g_transferQueue;
};

#endif
