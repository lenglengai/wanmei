#include "../DefInc.h"
#include "../log/LogService.h"
#include "../init/InitService.h"
#include "SettingService.h"

#ifdef __SETTING__
namespace std {

	const char * SettingService::streamName()
	{
		return "settingService";
	}

	const char * SettingService::streamUrl()
	{
	#ifdef __SEVRECV__
		return "serverSetting.xml";
	#endif
	#ifdef __CLTRECV__
		return "clientSetting.xml";
	#endif
	}

#ifdef __SEVRECV__
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
		if (high != mHigh) return ERRORINT::MUSTUPDATE;
		if (lower != mLower) return ERRORINT::HAVEUPDATE;
		return ERRORINT::SUCESS;
	}

	void SettingService::runPreinit(const string& nPath)
	{
		mSystemPath = nPath;
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunLoad0.connect(boost::bind(&SettingService::runLoad, this));
	}

	void SettingService::runLoad()
	{
		this->initUrlStream(this);
	}

	const string& SettingService::systemPath()
	{
		return mSystemPath;
	}

	SettingService::SettingService()
		: mSystemPath("")
		, mHigh(0)
		, mLower(0)
#ifdef __SEVRECV__
		, mServerCount(0)
		, mServerId(0)
#endif
	{
	}

	SettingService::~SettingService()
	{
		mSystemPath = "";
		mLower = 0;
		mHigh = 0;
#ifdef __SEVRECV__
		mServerCount = 0;
		mServerId = 0;
#endif
	}

}
#endif
