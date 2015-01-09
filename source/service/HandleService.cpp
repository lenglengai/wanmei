#include "../Include.h"

namespace std {

#ifdef __CONSOLE__
	const StringWriterPtr HandleService::commandInfo(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		string className_(""); 
		__i32 classid_ = __classinfo<HandleService>(className_);
		stringWriter_->runString(className_, "className");
		stringWriter_->runInt32(classid_, "classId");
		stringWriter_->runInt32(mHandleCount, "handleCount");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
#endif
	
	void HandleService::addContext(ContextPtr& nContext, const __i32 nIndex)
	{
		if (nIndex > mHandleCount) {
			LogService& logService_ = Service<LogService>::instance();
			logService_.logError(log_1(nIndex));
			return;
		}
		HandlePtr& handle = mHandles[nIndex - 1];
		handle->addContext(nContext);
	}

	const char * HandleService::streamName() const
	{
		return "handleService";
	}

	const char * HandleService::streamUrl() const
	{
	#ifdef __CLIENT__
		return "handleClient.xml";
	#endif
	#ifdef __SERVER__
		return "handleServer.xml";
	#endif
	}
	
	bool HandleService::runPreinit()
	{
	#ifdef __CONSOLE__
		this->registerCommand("info", std::bind(&HandleService::commandInfo, this, placeholders::_1));
	#endif
		return true;
	}
	
	void HandleService::runConfig()
	{
		ArchiveService& archiveService_ = Service<ArchiveService>::instance();
		archiveService_.loadStream(this);
	}
	
	void HandleService::initBegin()
	{
		for (__i32 i = 0; i < mHandleCount; ++i) {
			HandlePtr handle(new Handle());
			mHandles[i] = handle;
		}
	}

	void HandleService::starting()
	{
		map<__i32, HandlePtr>::iterator it = mHandles.begin();
		for ( ; it != mHandles.end(); ++it ) {
			HandlePtr& handle = it->second;
			handle->runStart();
		}
	}

	void HandleService::stoping()
	{
		for (auto it : mHandles) {
			HandlePtr& handle = it.second;
			handle->runStop();
		}
		for (auto it : mHandles) {
			HandlePtr& handle = it.second;
			handle->runJoin();
		}
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
	
	static Service<HandleService> sHandleService;

}
