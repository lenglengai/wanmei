#pragma once

#include <boost/thread.hpp>
#include <boost/atomic.hpp>

#include "Context.h"

namespace std {

	class Handle : boost::noncopyable
	{
	public:
		void addContext(ContextPtr& nContext);
		void runStart();
		void runStop();

	private:
		bool runInternal();
		void runHandle();
		void runClear();

	public:
		Handle();
		~Handle();

	private:
		boost::shared_ptr<boost::thread> mThread;
		mutable boost::atomic<bool> mStop;
		list<ContextPtr> mContexts;
	};
	typedef boost::shared_ptr<Handle> HandlePtr;

}