#pragma once

namespace std {

	class __funapi Handle : boost::noncopyable
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
		std::list<ContextPtr> mContexts;
		std::atomic<bool> mStop;
	};
	typedef std::shared_ptr<Handle> HandlePtr;

}
