#include "../Include.h"

namespace std {

#ifdef __CONSOLE__
	const StringWriterPtr IoService::commandInfo(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		string className_(""); 
		__i32 classid_ = __classinfo<IoService>(className_);
		stringWriter_->runString(className_, "className");
		stringWriter_->runInt32(classid_, "classId");
		stringWriter_->runInt32(mIoServiceCount, "ioServiceCount");
		return stringWriter_;
	}
	
	const StringWriterPtr IoService::commandReload(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		this->runLoad();
		stringWriter_->runInt32(mIoServiceCount, "ioServiceCount");
		return stringWriter_;
	}
#endif

	const char * IoService::streamName() const
	{
		return "ioService";
	}
	
	const char * IoService::streamUrl() const
	{
	#ifdef __SERVER__
		return "ioServer.xml";
	#endif
	#ifdef __CLIENT__
		return "ioClient.xml";
	#endif
	}
	
	bool IoService::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunLoad0.connect(boost::bind(&IoService::runLoad, this));
		initService_.m_tRunInit0.connect(boost::bind(&IoService::runInit, this));
		initService_.m_tRunStart0.connect(boost::bind(&IoService::runStart, this));
		initService_.m_tRunRun.connect(boost::bind(&IoService::runRun, this));
		initService_.m_tRunStop.connect(boost::bind(&IoService::runStop, this));
	#ifdef __CONSOLE__
		this->registerCommand("info", std::bind(&IoService::commandInfo, this, placeholders::_1));
		this->registerCommand("reload", std::bind(&IoService::commandReload, this, placeholders::_1));
	#endif
		return true;
	}
	
	void IoService::runLoad()
	{
		ArchiveService& archiveService_ = Singleton<ArchiveService>::instance();
		archiveService_.loadStream(this);
	}
	
	void IoService::runInit()
	{
		for (__i32 i = 0; i < mIoServiceCount; ++i) {
			IoServicePtr ioService(new asio::io_service());
			WorkPtr work(new asio::io_service::work(*ioService));
			mIoServices.push_back(ioService);
			mWorks.push_back(work);
		}
	}
	
	void IoService::runStart()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		mSignals.reset(new asio::signal_set(this->getIoService()));
		mSignals->add(SIGINT); mSignals->add(SIGTERM);
		mSignals->async_wait(boost::bind(&InitService::runStop, &initService_));
	}

	void IoService::runRun()
	{
		vector<shared_ptr<thread>> threads;
		for (size_t i = 0; i < mIoServices.size(); ++i) {
			shared_ptr<thread> thread_(new thread(boost::bind(&asio::io_service::run, mIoServices[i])));
			threads.push_back(thread_);
		}
	#ifdef __RUNING__
		for (size_t i = 0; i < threads.size(); ++i) {
			threads[i]->join();
		}
	#endif
	}

	void IoService::runStop()
	{
		for (size_t i = 0; i < mIoServices.size(); ++i) {
			mIoServices[i]->stop();
		}
	}
	
	asio::io_service& IoService::getIoService()
	{
		asio::io_service& ioService = (*(mIoServices[mNextIoService]));
		++mNextIoService;
		if (mNextIoService == mIoServices.size()) {
			mNextIoService = 0;
		}
		return ioService;
	}

	void IoService::runClear()
	{
		//mIoServices.clear();
		//mWorks.clear();
		mNextIoService = 0;
		mIoServiceCount = 1;
	}

	IoService::IoService()
	{
		this->runClear();
	}

	IoService::~IoService()
	{
		this->runClear();
	}
	
	static Preinit0<IoService> sIoServicePreinit;

}
