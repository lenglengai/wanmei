#pragma once

namespace std {

	class __funapi ClosedService : boost::noncopyable
	#ifdef __CONSOLE__
		, public IConsole
	#endif
	{
	public:
		ClosedMgrPtr& getClosedMgr(__i32 nModule, __i32 nClosedMgr);
	#ifdef __CONSOLE__
		void runCommand(std::list<std::string>& nCommand);
	#endif
	
		bool runPreinit();
		void runInit();
		
		ClosedService();
		~ClosedService();
		
	private:
		std::map<__i32, ClosedModulePtr> mClosedModules;
	};

}
