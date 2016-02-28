#ifndef curious_server_application_h
#define curious_server_application_h

#include <Ice/Ice.h>
#include <string>
#include <vector>
#include "LogWrapper.h"
#include "CuriousMasterInterfaceI.h"
#include "CuriousRegisterHandleThread.h"

using namespace Ice;
using namespace taf;
using namespace log4cplus;

namespace Curious
{
	class ServerApplication : public Ice::Application
	{
	public:
		virtual ~ServerApplication();

		virtual int run(int argc, char* argv[]);

	private:
		std::vector<RegisterHandleThreadPtr> _registerThreads;	
	};
}

#endif
