#include "CuriousTransferRequest.h"

namespace Curious
{
	TransferRequest::TransferRequest(const AMD_GateInterface_transferPtr& callback, const Message_S& message)
		: _callback(callback), _message(message)
	{

	}

	bool TransferRequest::process()
	{
		return true;
	}

	void TransferRequest::exception()
	{
		_callback->ice_exception();
	}

	time_t TransferRequest::time()
	{
		return _time;
	}

	std::string TransferRequest::detail()
	{
		std::stringstream ss;

		ss << "from=" << message.sFrom << ", to=" << message.sTo << ", time=" << message.sTime << ", message=" << message.sMessage << " trasnfer_count=" << message.iTransferCount;

		return ss.str();
	}
}
