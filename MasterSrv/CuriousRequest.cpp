#include "CuriousRequest.h"

namespace Curious
{
	RegisterRequest::RegisterRequest(const AMD_MasterInterface_registerPtr& cb,
		                             const std::string& sServerIP)
	 : _callback(cb), _sServerIP(sServerIP), _time(time(NULL))
	{

	}

	bool RegisterRequest::process()
	{
		std::string sNextServer("");

		int iRet = ServerDataInfo::getInstance()->registerServerIP(_sServerIP, sNextServer);
		if (iRet != 0)
		{
			LOG_ERROR("register_error, server_ip=" << _sServerIP << ", ret=" << iRet);
			return false;
		}

		_callback->ice_response(iRet, sNextServer);

		LOG_DEBUG("server_ip=" <<_sServerIP << ", next_ip=" <<sNextServer);
		
		return true;
	}

	void RegisterRequest::exception()
	{
		_callback->ice_exception();
	}

	time_t RegisterRequest::getTime()
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
