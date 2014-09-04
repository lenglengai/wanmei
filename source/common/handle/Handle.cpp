#include "../DefInc.h"

#include "Handle.h"

#ifdef __HANDLE__
namespace std {

	void Handle::addContext(ContextPtr& nContext)
	{
		mContexts.push_back(nContext);
	}

	void Handle::runStart()
	{
		mThread.reset(new std::thread(boost::bind(&Handle::runHandle, this)));
	}

	void Handle::runHandle()
	{
		mStop = false;
		while (this->runInternal());
		mStop = true;
	}

	void Handle::runStop()
	{
		mStop = true;
		mThread->join();
	}

	void Handle::runClear()
	{
		mContexts.clear();
		mThread.reset();
		mStop = true;
	}

	bool Handle::runInternal()
	{
		if (true == mStop) return false;
		std::list<ContextPtr>::iterator it = mContexts.begin();
		for (; it != mContexts.end(); ++it) {
			ContextPtr& context_ = (*it);
			context_->runContext();
		}
		std::chrono::milliseconds dura(1000);
		std::this_thread::sleep_for(dura);
		return true;
	}

	Handle::Handle()
	{
		this->runClear();
	}

	Handle::~Handle()
	{
		this->runClear();
	}

}
#endif
