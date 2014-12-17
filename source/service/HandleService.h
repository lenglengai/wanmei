#pragma once

namespace std {

	class __funapi HandleService : IService
	{
	public:
	#ifdef __CONSOLE__
		StringWriterPtr runCommand(std::list<std::string>& nCommand);
	#endif
		void addContext(ContextPtr& nContext, __i32 nIndex);
		
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
