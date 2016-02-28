#include "CuriousRequest.h"

namespace Curious
{
	RegisterRequest::RegisterRequest(const AMD_MasterInterface_registerPtr& callback,
		                             const std::string& sServerIP)
	 : _callback(callback), _sServerIP(sServerIP), _time(time(NULL))
	{

	}

	bool RegisterRequest::process()
	{
		std::string sNextServer("");

		int iRet = ServerDataInfo::getInstance()->register(_sServerIP, sNextServer);
		
		_callback->ice_response(iRet, sNextServer);

		return true;
	}

	void RegisterRequest::exception()
	{
		_callback->ice_exception();
	}

	time_t RegisterRequest::time()
	{
		return _time;
	}

	std::string RegisterRequest::detail()
	{
		std::stringstream ss;

		ss << _sServerIP;

		return ss.str();
	}

}
