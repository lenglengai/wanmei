#include "../com.common/DefInc.h"
#include "Handle.h"

namespace std {

	void Handle::addContext(ContextPtr& nContext)
	{
		mContexts.push_back(nContext);
	}

	void Handle::runStart()
	{
		mThread.reset(new boost::thread(boost::bind(&Handle::runHandle, this)));
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
		boost::this_thread::sleep(boost::posix_time::seconds(1));
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
