#ifndef curious_server_application_h
#define curious_server_application_h

#include <Ice/Ice.h>
#include <string>
#include <vector>
#include "CuriousGateInterfaceI.h"
#include "CuriousTransferHandleThread.h"
#include "CuriousMessageListen.h"

using namespace Ice;
using namespace taf;

namespace Curious
{
	class ServerApplication : public Ice::Application
	{
	public:
		virtual ~ServerApplication();

		virtual int run(int argc, char* argv[]);

	private:
		std::vector<TransferHandleThreadPtr> _transferThreads;
	};
}

#endif
