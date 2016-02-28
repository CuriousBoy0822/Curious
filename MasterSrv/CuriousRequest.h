#ifndef curious_request_h
#define curious_request_h

#include <string>
#include <sstream>
#include <time.h>
#include <sys/time.h>
#include "tc_autoptr.h"
#include "tc_monitor.h"
#include "CuriousMasterInterface.h"

using namespace taf;

namespace Curious
{
	class RegisterRequest : public taf::HandleBase
	{
	private:
		AMD_MasterInterface_registerPtr _callback;
		std::string            _sServerIP;
		time_t				   _time;

	public:
		RegisterRequest(const AMD_MasterInterface_registerPtr& callback, 
			            const std::string& sServerIP);
		
		virtual ~RegisterRequest() {};

		//processing
		bool process();
		
		//return exception
		void exception();

		//for return info
		std::string detail(); 

		//return time
		time_t time();
	};

	typedef taf::TC_AutoPtr<RegisterRequest> RegisterRequestPtr;
};


#endif
