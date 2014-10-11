#include "../Common.h"

#ifdef __WINDOW__
#include <windows.h>
#else
#include <sysconf.h>
#endif

#ifdef __WITHCPU__
namespace std {

	__i16 CpuService::getCpuCount()
	{
		return mCpuCount;
	}
	
	bool CpuService::runPreinit()
	{
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("CpuService run runPreinit!"));
#ifdef __WINDOW__
		SYSTEM_INFO si;
		GetSystemInfo(&si);
		mCpuCount = si.dwNumberOfProcessors;
#else
		mCpuCount = sysconf(_SC_NPROCESSORS_CONF);
#endif
		logService_.logInfo(log_1("CpuService run runPreinit finish!"));
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
	
}
#endif
