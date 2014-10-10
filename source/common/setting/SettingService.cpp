#include "../Common.h"

#ifdef __SETTING__
namespace std {

#ifdef __SERVER__
	__i32 SettingService::checkServerId(__i32 nServerId)
	{
		if (mServerId == nServerId) return ERRORINT::SUCESS;
		return ERRORINT::SERVERERROR;
	}

	void SettingService::setServerId(__i16 nServerId)
	{
		mServerId = nServerId;
	}

	__i16 SettingService::getServerId()
	{
		return mServerId;
	}

	void SettingService::setServerCount(__i16 nServerCount)
	{
		mServerCount = nServerCount;
	}

	__i16 SettingService::getServerCount()
	{
		return mServerCount;
	}
#endif

	__i32 SettingService::checkVersion(__i32 nVersion)
	{
		__i32 high = nVersion >> 12;
		__i32 lower = nVersion & 0xFFF;
		if (high != VERHIGH) return ERRORINT::MUSTUPDATE;
		if (lower != VERLOW) return ERRORINT::HAVEUPDATE;
		return ERRORINT::SUCESS;
	}

	void SettingService::runPreinit(const char * nPath)
	{
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("SettingService run runPreinit!"));
		
		mSystemPath = nPath;
		
		logService_.logInfo(log_1("SettingService run runPreinit finish!"));
	}

	const string& SettingService::systemPath()
	{
		return mSystemPath;
	}

	SettingService::SettingService()
		: mSystemPath("")
#ifdef __SERVER__
		, mServerCount(0)
		, mServerId(0)
#endif
	{
	}

	SettingService::~SettingService()
	{
		mSystemPath = "";
#ifdef __SERVER__
		mServerCount = 0;
		mServerId = 0;
#endif
	}

}
#endif
