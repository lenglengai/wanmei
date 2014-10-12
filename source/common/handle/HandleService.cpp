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

	bool HandleService::runPreinit()
	{
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("HandleService run runPreinit"));
	#endif
#if defined(__SERVER__) && defined(__CPU__)
		CpuService& cpuService_ = Singleton<CpuService>::instance();
		mHandleCount = cpuService_.getCpuCount();
#endif
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&HandleService::runInit, this));
		initService_.m_tRunStart1.connect(boost::bind(&HandleService::runStart, this));
		initService_.m_tRunStop.connect(boost::bind(&HandleService::runStop, this));
	#ifdef __LOG__
		logService_.logInfo(log_1("HandleService run runPreinit finish!"));
	#endif
		return true;
	}

	void HandleService::runInit()
	{
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("init handle service"));
	#endif
		for (__i32 i = 0; i < mHandleCount; ++i) {
			HandlePtr handle(new Handle());
			mHandles[i] = handle;
		}
	#ifdef __LOG__
		logService_.logInfo(log_1("init handle service finish!"));
	#endif
	}

	void HandleService::runStart()
	{
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("run start handle service"));
	#endif
		std::map<__i32, HandlePtr>::iterator it = mHandles.begin();
		for ( ; it != mHandles.end(); ++it ) {
			HandlePtr& handle = it->second;
			handle->runStart();
		}
	#ifdef __LOG__
		logService_.logInfo(log_1("start handle service finish"));
	#endif
	}

	void HandleService::runStop()
	{
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("stop handle service"));
	#endif
		std::map<__i32, HandlePtr>::iterator it = mHandles.begin();
		for (; it != mHandles.end(); ++it) {
			HandlePtr& handle = it->second;
			handle->runStop();
		}
	#ifdef __LOG__
		logService_.logInfo(log_1("stop handle service finish!"));
	#endif
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
	
	static Preinit<HandleService> sHandleServicePreinit;

}
#endif

