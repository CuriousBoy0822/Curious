#ifndef curious_register_handle_thread_h
#define curious_register_handle_thread_h

#include <string>
#include <time.h>
#include <sys/time.h>
#include "tc_monitor.h"
#include "tc_thread_queue.h"
#include "tc_autoptr.h"
#include "tc_thread.h"
#include "LogWrapper.h"

#include "CuriousMasterInterfaceI.h"

using namespace taf;
using namespace log4cplus;

namespace Curious
{
	class RegisterHandleThread : public taf::TC_Thread,
	                             public taf::TC_ThreadLock,
	                             public taf::TC_HandleBase
	{
	public:
		RegisterHandleThread(const int iMaxQueueSize, 
			                                const int iTimeout);

		virtual ~RegisterHandleThread() {}

		void terminate();

	protected:
		virtual void run();

	private:
		bool _bTerminate;
		int    _iMaxQueueSize;
		int    _iTimeout;
	};

	typedef taf::TC_AutoPtr<RegisterHandleThread> RegisterHandleThreadPtr;
};

#endif
