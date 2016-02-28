#ifndef curious_server_data_info_h
#define curious_server_data_info_h

#include <vector>
#include <set>
#include <string>
#include "tc_singleton.h"
#include "tc_thread.h"

using namespace taf;

namespace Curious
{
	typedef std::vector<std::string>  ServerInfoCache_t;
	typedef std::set<std::string>	  ServerInfoCacheSet_t;

	class ServerDataInfo 
	    : public taf::TC_Singleton<ServerDataInfo>
	{
	public:
		ServerDataInfo() {}
		virtual ~ServerDataInfo() {}

		int registerServerIP(const std::string& sServerIP, std::string& sNextIp);

		int size();

	private:
		TC_ThreadMutex             _mutex;
		ServerInfoCache_t          _serverInfo;
		ServerInfoCacheSet_t     _serverInfoSet;
	};
};

#endif
