#include "../Common.h"

#ifdef __HANDLE__
namespace std {

	const char * HandleService::streamName()
	{
		return "handleService";
	}

	const char * HandleService::streamUrl()
	{
	#ifdef __CLIENT__
		return "common/handle/config/clientHandle.xml";
	#endif 
	#ifdef __SERVER__
		return "common/handle/config/serverHandle.xml";
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
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("HandleService run runPreinit"));
		
		ArchiveService& archiveService_ = Singleton<ArchiveService>::instance();
		archiveService_.m_tRunConfigure.connect(boost::bind(&HandleService::runLoad, this));

		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&HandleService::runInit, this));
		initService_.m_tRunStart1.connect(boost::bind(&HandleService::runStart, this));
		initService_.m_tRunStop.connect(boost::bind(&HandleService::runStop, this));
		initService_.registerArchive(this->streamUrl());
		
		logService_.logInfo(log_1("HandleService run runPreinit finish!"));
	}

	void HandleService::runLoad()
	{
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("run loading handle service"));
		
		ArchiveService& archiveService_ = Singleton<ArchiveService>::instance();
		archiveService_.initUrlStream(this);
		
		logService_.logInfo(log_1("loading handle service finish!"));
	}

	void HandleService::runInit()
	{
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("init handle service"));
		for (int i = 0; i < mHandleCount; ++i) {
			HandlePtr handle(new Handle());
			mHandles[i] = handle;
		}
		logService_.logInfo(log_1("init handle service finish!"));
	}

	void HandleService::runStart()
	{
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("run start handle service"));
		std::map<int, HandlePtr>::iterator it = mHandles.begin();
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
		std::map<int, HandlePtr>::iterator it = mHandles.begin();
		for (; it != mHandles.end(); ++it) {
			HandlePtr& handle = it->second;
			handle->runStop();
		}
		logService_.logInfo(log_1("stop handle service finish!"));
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

