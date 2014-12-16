#pragma once

namespace std {

	class __funapi Handle : noncopyable
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
		shared_ptr<thread> mThread;
		list<ContextPtr> mContexts;
		atomic<bool> mStop;
	};
	typedef shared_ptr<Handle> HandlePtr;
	typedef weak_ptr<Handle> HandleWtr;

}
