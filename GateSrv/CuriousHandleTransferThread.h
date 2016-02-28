#ifndef curious_handle_transfer_thread_h
#define curious_handle_transfer_thread_h

#include <string>
#include "tc_monitor.h"
#include "tc_thread_queue.h"
#include "tc_autoptr.h"
#include "tc_thread.h"

#include "CuriousGateInterfaceI.h"

namespace Curious
{
	class TransferHandleThread : public taf::TC_Thread,
	                             public taf::TC_ThreadLock,
	                             public taf::TC_HandleBase
	{
	public:
		TransferHandleThread(const int iMaxQueueSize, const int iTimeout);

		virtual ~TransferHandleThread() {}

		void terminate();

	protected:
		virtual void run();

	private:
		bool _bTerminate;
		int  _iMaxQueueSize;
		int  _iTimeout;
	};

	typedef taf::TC_AutoPtr<TransferHandleThread> TransferHandleThreadPtr;
};

#endif
