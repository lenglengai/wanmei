#include "DefInc.h"
#include "Handle.h"
#include "HandleService.h"

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
		SettingService& settingService_ = Singleton<SettingService>::instance();
		settingService_.initUrlStream(this);
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit.connect(boost::bind(&HandleService::runInit, this));
		initService_.m_tRunStart.connect(boost::bind(&HandleService::runStart, this));
		initService_.m_tRunStop.connect(boost::bind(&HandleService::runStop, this));
	}

	void HandleService::runInit()
	{
		for (int i = 0; i < mHandleCount; ++i) {
			HandlePtr handle(new Handle());
			mHandles[i] = handle;
		}
	}

	void HandleService::runStart()
	{
		map<int, HandlePtr>::iterator it = mHandles.begin();
		for ( ; it != mHandles.end(); ++it )
		{
			HandlePtr& handle = it->second;
			handle->runStart();
		}
	}

	void HandleService::runStop()
	{
		map<int, HandlePtr>::iterator it = mHandles.begin();
		for (; it != mHandles.end(); ++it)
		{
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
