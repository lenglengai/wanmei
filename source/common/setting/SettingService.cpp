#include "../Common.h"

namespace std {

#ifdef __SERVER__
	__i32 SettingService::checkVersion(__i32 nVersion)
	{
		__i32 high = nVersion >> 12;
		__i32 lower = nVersion & 0xFFF;
		if (high != VERHIGH) return ERRORINT::MUSTUPDATE;
		if (lower != VERLOW) return ERRORINT::HAVEUPDATE;
		return ERRORINT::SUCESS;
	}
#endif

	bool SettingService::runPreinit()
	{
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("SettingService run runPreinit!"));
	#endif
		
		//mSystemPath = nPath;
		
	#ifdef __LOG__
		logService_.logInfo(log_1("SettingService run runPreinit finish!"));
	#endif
		return true;
	}

	const string& SettingService::systemPath()
	{
		return mSystemPath;
	}

	SettingService::SettingService()
		: mSystemPath("")
	{
	}

	SettingService::~SettingService()
	{
		mSystemPath = "";
	}
	
	static Preinit<SettingService> sSettingServicePreinit;
}
