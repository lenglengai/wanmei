#include "../Common.h"

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

	void SettingService::runPreinit(const char * nPath)
	{
		mSystemPath = nPath;
		ArchiveService& archiveService_ = Singleton<ArchiveService>::instance();
		archiveService_.m_tRunConfigure.connect(boost::bind(&SettingService::runLoad, this));
		initService_.registerArchive(this->streamUrl());
	}

	void SettingService::runLoad()
	{
		ArchiveService& archiveService_ = Singleton<ArchiveService>::instance();
		archiveService_.initUrlStream(this);
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
#ifdef __SEVRECV__
		mServerCount = 0;
		mServerId = 0;
#endif
	}

}
#endif
