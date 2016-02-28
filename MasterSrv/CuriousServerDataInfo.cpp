#include "CuriousServerDataInfo.h"

namespace Curious
{
	int CuriousServerDataInfo::register(const std::string& sServerIP, std::string& sNextIp)
	{
		TC_LockT<TC_ThreadMutex> lock(_mutex);

		if (_serverInfo.size() == 0)
		{
			_serverInfoSet.insert(sServerIP);
			_serverInfo.insert(sServerIP);

			sNextIp = sServerIP;
		}
		else 
		{
			ServerInfoCacheSet_t::iterator it = _serverInfoSet.find(sServerIP);

			if (it != _serverInfoSet.end()) // find same 
			{
				return -1;
			}

			//find the rear server, and notify the next pasing server
			std::string sRearServerIP = _serverInfo[_serverInfo.size()-1];

			sNextIp = _serverInfo[0];
			
			_serverInfo.insert(sServerIP);
			_serverInfoSet.insert(sServerIP);
		}

		return 0;		
	}

	int CuriousServerDataInfo::size()
	{
		TC_LockT<TC_ThreadMutex> lock(_mutex);

		return _serverInfo.size();
	}
};
