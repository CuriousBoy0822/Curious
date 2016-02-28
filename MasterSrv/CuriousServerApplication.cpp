#include "CuriousServerApplication.h"

namespace Curious
{
	ServerApplication::~ServerApplication()
	{
		for (size_t i=0; i<_registerThreads.size(); ++i)
		{
			_registerThreads[i]->terminate();
			_registerThreads[i]->getThreadControl().join();
		}
	}

	int ServerApplication::run(int argc, char* argv[])
	{
		PropertiesPtr properties = communicator()->getProperties();

		std::string sLog = properties->getProperty("curious.master.log");
		std::string sProxyId = properties->getProperty("curious.master.proxyid");
		int iMaxQueueSize = properties->getPropertyAsInt("curious.master.queuesize");
		int iTimeout = properties->getPropertyAsInt("curious.master.timeout");
		int iRegisterThreadSize = properties->getPropertyAsInt("curious.master.registerthreadsize");
		
		for (int i=0; i<iRegisterThreadSize; ++i)
		{
			_registerThreads.push_back(new RegisterHandleThread(iMaxQueueSize, iTimeout));
			_registerThreads.back()->start();
		}

		MasterInterfacePtr master = new CuriousMasterInterfaceI;
		ObjectAdapterPtr adapter = communicator()->createObjectAdapter(sProxyId);
		adapter->add(master, communicator()->stringToIdentity(sProxyId));
		adapter->activate();
		communicator()->waitForShutdown();

		return 0;
	}
}

using namespace Curious;

int main(int argc, char* argv[])
{
	ServerApplication app;

	return app.main(argc, argv, "./conf/master.conf");
}
