#pragma once

namespace std {

	class __funapi HandleService : noncopyable
	#ifdef __CONSOLE__
		, public IConsole
	#endif
	{
	public:
	#ifdef __CONSOLE__
		void runCommand(std::list<std::string>& nCommand, StringWriter& nStringWriter) override final;
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
