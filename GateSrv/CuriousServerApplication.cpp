#include "CuriousServerApplication.h"

namespace Curious
{
	ServerApplication::~ServerApplication()
	{

	}

	int ServerApplication::run(int argc, char* argv[])
	{
		PropertiesPtr properties = communicator()->getProperties();

		std::string sLog = properties->getProperty("curious.gate.log");
		
	}
};

using namespace Curious;

int main(int argc, char* argv[])
{

}
