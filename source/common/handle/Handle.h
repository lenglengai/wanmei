#pragma once

#include <thread>
#include <atomic>
#include <chrono>

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
		std::shared_ptr<std::thread> mThread;
		volatile atomic<bool> mStop;
		list<ContextPtr> mContexts;
	};
	typedef std::shared_ptr<Handle> HandlePtr;

}
