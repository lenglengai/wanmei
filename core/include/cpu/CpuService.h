#pragma once

#ifdef __WITHCPU__
namespace std {
	
	class __funapi CpuService : boost::noncopyable
	#ifdef __CONSOLE__
		, public IConsole
	#endif
	{
	public:
	#ifdef __CONSOLE__
		void runCommand(std::list<std::string>& nCommand);
	#endif
		__i16 getCpuCount();
		bool runPreinit();
		void runInit();
		
		CpuService();
		~CpuService();
		
	private:
		__i16 mCpuCount;
	};
	
}
#endif
