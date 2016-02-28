#include "CuriousHandleTransferThread.h"

namespace Curious
{
	TransferHandleThread::TransferHandleThread() 
	     : _iMaxQueueSize(iMaxQueueSize), _iTimeout(iTimeout), _bTerminate(false)
	{

	}

	void TransferHandleThread::terminate()
	{
		_bTerminate = true;

		TC_ThreadLock::Lock lock(*this);
		notifyAll();
	}

	void TransferHandleThread::run()
	{
		while (!_bTerminate)
		{
			TransferRequestPtr reqPtr;
			if (g_transferQueue.pop_front(reqPtr, 100))
			{
				if (g_transferQueue.size() > _iMaxQueueSize)
				{

				}

				if (time(NULL)-reqPtr->time() >_iTimeout)
				{
					reqPtr->exception();
				}
				else if (!reqPtr->process())
				{

				}
			}
		}
	}
	
}
