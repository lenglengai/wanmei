#include "../../include/Include.h"

namespace std {

	__i16 SettingService::checkVersion(__i16 nVersion)
	{
		__i32 high = nVersion >> 10;
		__i32 lower = nVersion & 0x3FF;
		if (high != VERHIGH) return ERRORINT::MUSTUPDATE;
		if (lower != VERLOW) return ERRORINT::HAVEUPDATE;
		return ERRORINT::SUCESS;
	}

	__i16 SettingService::getVersion()
	{
		return ((VERHIGH << 10) + VERLOW);
	}

	bool SettingService::runPreinit()
	{
		//mSystemPath = nPath;
		
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
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
