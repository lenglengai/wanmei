#include "../Common.h"

#ifdef __HANDLE__
namespace std {

	void HandleService::addContext(ContextPtr& nContext, __i32 nIndex)
	{
		__i32 index_ = nIndex % mHandleCount;
		HandlePtr& handle = mHandles[index_];
		handle->addContext(nContext);
	}

	__i32 HandleService::getHandleCount()
	{
		return mHandleCount;
	}

	void HandleService::runPreinit()
	{
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("HandleService run runPreinit"));

#if defined(__SERVER__) && defined(__CPU__)
		CpuService& cpuService_ = Singleton<CpuService>::instance();
		mHandleCount = cpuService_.getCpuCount();
#endif
		
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&HandleService::runInit, this));
		initService_.m_tRunStart1.connect(boost::bind(&HandleService::runStart, this));
		initService_.m_tRunStop.connect(boost::bind(&HandleService::runStop, this));
		
		logService_.logInfo(log_1("HandleService run runPreinit finish!"));
	}

	void HandleService::runInit()
	{
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("init handle service"));
		for (__i32 i = 0; i < mHandleCount; ++i) {
			HandlePtr handle(new Handle());
			mHandles[i] = handle;
		}
		logService_.logInfo(log_1("init handle service finish!"));
	}

	void HandleService::runStart()
	{
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("run start handle service"));
		std::map<__i32, HandlePtr>::iterator it = mHandles.begin();
		for ( ; it != mHandles.end(); ++it ) {
			HandlePtr& handle = it->second;
			handle->runStart();
		}
		logService_.logInfo(log_1("start handle service finish"));
	}

	void HandleService::runStop()
	{
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("stop handle service"));
		std::map<__i32, HandlePtr>::iterator it = mHandles.begin();
		for (; it != mHandles.end(); ++it) {
			HandlePtr& handle = it->second;
			handle->runStop();
		}
		logService_.logInfo(log_1("stop handle service finish!"));
	}

	HandleService::HandleService()
		: mHandleCount(1)
	{
		mHandles.clear();
	}

	HandleService::~HandleService()
	{
		mHandles.clear();
		mHandleCount = 1;
	}

}
#endif

