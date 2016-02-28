#include "CuriousServerDataInfo.h"

namespace Curious
{
	int ServerDataInfo::registerServerIP(const std::string& sServerIP, std::string& sNextIp)
	{
		TC_LockT<TC_ThreadMutex> lock(_mutex);

		if (_serverInfo.size() == 0)
		{
			_serverInfoSet.insert(sServerIP);
			_serverInfo.push_back(sServerIP);

			sNextIp = sServerIP;
		}
		else 
		{
			ServerInfoCacheSet_t::iterator it = _serverInfoSet.find(sServerIP);

			if (it != _serverInfoSet.end()) // find same 
			{
				return -1;
			}

			sNextIp = _serverInfo[0];
			
			_serverInfo.push_back(sServerIP);
			_serverInfoSet.insert(sServerIP);
		}
		
		return 0;		
	}

	int ServerDataInfo::size()
	{
		TC_LockT<TC_ThreadMutex> lock(_mutex);

		return _serverInfo.size();
	}
};
