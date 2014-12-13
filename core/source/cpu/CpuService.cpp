#include "../../include/Include.h"

#ifdef __WINDOW__
#include <windows.h>
#else
#include <sysconf.h>
#endif

#ifdef __WITHCPU__
namespace std {

#ifdef __CONSOLE__
	void CpuService::runCommand(std::list<std::string>& nCommand)
	{
	#ifdef __CLIENT__
		std::cout << mCpuCount << std::endl;
	#endif
	}
#endif

	__i16 CpuService::getCpuCount()
	{
		return mCpuCount;
	}
	
	void CpuService::runInit()
	{
	#ifdef __CONSOLE__
		ConsoleService& consoleService_ = Singleton<ConsoleService>::instance();
		consoleService_.registerConsole(this);
	#endif
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}
	
	bool CpuService::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&CpuService::runInit, this));
		
#ifdef __WINDOW__
		SYSTEM_INFO si;
		GetSystemInfo(&si);
		mCpuCount = static_cast<__i16>(si.dwNumberOfProcessors);
#else
		mCpuCount = sysconf(_SC_NPROCESSORS_CONF);
#endif

		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
		return true;
	}
	
	CpuService::CpuService()
		: mCpuCount(1)
	{
	}
	
	CpuService::~CpuService()
	{
		mCpuCount = 0;
	}
	
	static Preinit<CpuService> sCpuServicePreinit;
	
}
#endif

