#ifndef curious_transfer_request_h
#define curious_transfer_request_h

#include <string>
#include <sstream>
#include <time.h>
#include <sys/time.h>
#include "tc_autoptr.h"
#include "tc_monitor.h"

#include "CuriousGateInterface.h"

using namespace taf;

namespace Curious
{
	class TransferRequest : public taf::HandleBase
	{
	private:
		AMD_GateInterface_transferPtr _callback;
		Message_S                     _message;
		time_t                        _time;

	public:
		TransferRequest(const AMD_GateInterface_transferPtr& callback,
                        const Message_S& message);

		virtual ~TransferRequest() {}

		//processing
		bool process();

		//return exception
		void exception();

		//for return info
		std::string detail();

		//return time
		time_t time();
	};

	typedef taf::TC_AutoPtr<TransferRequest> TransferRequestPtr;
};

#endif
