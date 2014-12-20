#pragma once

namespace std {

	class __funapi HandleService : public IService
	{
	public:
		void addContext(ContextPtr& nContext, __i32 nIndex);
		
	private:
	#ifdef __CONSOLE__
		StringWriterPtr commandInfo(const CommandArgs& nCommand);
	#endif
	public:
		bool runPreinit();
		void runInit();
		void runStart();
		void runStop();
		
		HandleService();
		~HandleService();
		
	private:
		map<__i32, HandlePtr> mHandles;
		__i32 mHandleCount;
	};

}
