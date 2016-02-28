#include "CuriousRegisterHandleThread.h"

namespace Curious
{
	RegisterHandleThread::RegisterHandleThread(const int iMaxQueueSize,
		                                       const int iTimeout)
	 : _iMaxQueueSize(iMaxQueueSize), _bTerminate(false), _iTimeout(iTimeout)
	{

	}

	void RegisterHandleThread::terminate()
	{
		_bTerminate = true;

		TC_ThreadLock::Lock lock(*this);
		notifyAll();
	}

	void RegisterHandleThread::run()
	{
		while (!_bTerminate)
		{
			RegisterRequestPtr reqPtr;
			if (g_registerQueue.pop_front(reqPtr, 100))
			{
				if (g_registerQueue.size() > iMaxQueueSize)
				{
			
				}
				
				if (time(NULL)-reqPtr->time() > _iTimeout)
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
