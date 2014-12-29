#include "../Include.h"

namespace std {

	void Handle::addContext(ContextPtr& nContext)
	{
		mContexts.push_back(nContext);
	}

	void Handle::runStart()
	{
		mThread.reset(new thread(boost::bind(&Handle::runHandle, this)));
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
	}
	
	void Handle::runJoin()
	{
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
		list<ContextPtr>::iterator it = mContexts.begin();
		for (; it != mContexts.end(); ++it) {
			ContextPtr& context_ = (*it);
			context_->runContext();
		}
		chrono::milliseconds dura(200);
		this_thread::sleep_for(dura);
		return true;
	}

	Handle::Handle()
		: mStop(true)
	{
		this->runClear();
	}

	Handle::~Handle()
	{
		//this->runClear();
	}

}
