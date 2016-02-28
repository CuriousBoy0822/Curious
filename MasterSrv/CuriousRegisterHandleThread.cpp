#include "CuriousRegisterHandleThread.h"

namespace Curious
{
	RegisterHandleThread::RegisterHandleThread(const int iMaxQueueSize,
		                                                                       const int iTimeout) : _iMaxQueueSize(iMaxQueueSize), 
	       _bTerminate(false), _iTimeout(iTimeout)
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
				if (g_registerQueue.size() > _iMaxQueueSize)
				{
					LOG_ERROR("too many requests int the queue, please check the logic");
					continue;
				}
				
				if (time(NULL)-reqPtr->getTime() > _iTimeout)
				{
					reqPtr->exception();
				} 
				else if (!reqPtr->process())
				{
					LOG_ERROR("process error, info:" << reqPtr->detail());
				}
			}
		}
	}

}
