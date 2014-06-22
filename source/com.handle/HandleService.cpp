#include "../com.common/DefInc.h"
#include "HandleService.h"
#include "../com.setting/SettingService.h"
#include "../com.init/InitService.h"
#include "../com.log/LogService.h"

namespace std {

	const char * HandleService::streamName()
	{
		return "handleService";
	}

	const char * HandleService::streamUrl()
	{
		return "config/handle.xml";
	}

	void HandleService::addContext(ContextPtr& nContext, __i32 nMax, __i32 nIndex)
	{
		__i32 temp = nMax / mHandleCount;
		__i32 index = nIndex / temp;
		if ((nIndex % index) > 0) ++index;
		HandlePtr& handle = mHandles[index];
		handle->addContext(nContext);
	}

	int HandleService::getHandleCount()
	{
		return mHandleCount;
	}

	void HandleService::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunLoad.connect(boost::bind(&HandleService::runLoad, this));
		initService_.m_tRunInit.connect(boost::bind(&HandleService::runInit, this));
		initService_.m_tRunStart.connect(boost::bind(&HandleService::runStart, this));
		initService_.m_tRunStop.connect(boost::bind(&HandleService::runStop, this));
	}

	void HandleService::runLoad()
	{
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("加载线程处理器配置"));
		SettingService& settingService_ = Singleton<SettingService>::instance();
		settingService_.initUrlStream(this);
		loginService_.logInfo(log_1("线程处理器配置加载完成"));
	}

	void HandleService::runInit()
	{
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("初始化线程处理器"));
		for (int i = 0; i < mHandleCount; ++i) {
			HandlePtr handle(new Handle());
			mHandles[i] = handle;
		}
	}

	void HandleService::runStart()
	{
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("启动线程处理器"));
		map<int, HandlePtr>::iterator it = mHandles.begin();
		for ( ; it != mHandles.end(); ++it ) {
			HandlePtr& handle = it->second;
			handle->runStart();
		}
	}

	void HandleService::runStop()
	{
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("停止线程处理器"));
		map<int, HandlePtr>::iterator it = mHandles.begin();
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
