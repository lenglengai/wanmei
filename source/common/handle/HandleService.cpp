#include "../DefInc.h"
#include "../setting/SettingService.h"
#include "../init/InitService.h"
#include "../log/LogService.h"

#include "HandleService.h"

#ifdef __HANDLE__
namespace std {

	const char * HandleService::streamName()
	{
		return "handleService";
	}

	const char * HandleService::streamUrl()
	{
	#ifdef __CLIENT__
		return "config/clientHandle.xml";
	#endif 
	#ifdef __LOGIN__
		return "config/loginHandle.xml";
	#endif 
	#ifdef __SERVER__
		return "config/serverHandle.xml";
	#endif 
	#ifdef __ANDROID__
		return "config/androidHandle.xml";
	#endif
	}

	void HandleService::addContext(ContextPtr& nContext, __i32 nIndex)
	{
		__i32 index_ = nIndex % mHandleCount;
		HandlePtr& handle = mHandles[index_];
		handle->addContext(nContext);
	}

	int HandleService::getHandleCount()
	{
		return mHandleCount;
	}

	void HandleService::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunLoad0.connect(boost::bind(&HandleService::runLoad, this));
		initService_.m_tRunInit0.connect(boost::bind(&HandleService::runInit, this));
		initService_.m_tRunStart1.connect(boost::bind(&HandleService::runStart, this));
		initService_.m_tRunStop.connect(boost::bind(&HandleService::runStop, this));
	}

	void HandleService::runLoad()
	{
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("run loading handle service"));
		SettingService& settingService_ = Singleton<SettingService>::instance();
		settingService_.initUrlStream(this);
		loginService_.logInfo(log_1("loading handle service sucess!"));
	}

	void HandleService::runInit()
	{
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("init handle service"));
		for (int i = 0; i < mHandleCount; ++i) {
			HandlePtr handle(new Handle());
			mHandles[i] = handle;
		}
	}

	void HandleService::runStart()
	{
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("run handle service"));
		std::map<int, HandlePtr>::iterator it = mHandles.begin();
		for ( ; it != mHandles.end(); ++it ) {
			HandlePtr& handle = it->second;
			handle->runStart();
		}
	}

	void HandleService::runStop()
	{
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("stop handle service"));
		std::map<int, HandlePtr>::iterator it = mHandles.begin();
		for (; it != mHandles.end(); ++it) {
			HandlePtr& handle = it->second;
			handle->runStop();
		}
	}

	HandleService::HandleService()
		: mHandleCount(4)
	{
		mHandles.clear();
	}

	HandleService::~HandleService()
	{
		mHandles.clear();
		mHandleCount = 0;
	}

}
#endif

