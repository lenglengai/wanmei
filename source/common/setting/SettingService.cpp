#include "../Common.h"

#ifdef __SETTING__
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

	bool SettingService::runPreinit(const char * nPath)
	{
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("SettingService run runPreinit!"));
		
		mSystemPath = nPath;
		
		logService_.logInfo(log_1("SettingService run runPreinit finish!"));
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

}
#endif
