#include "../Common.h"

#include <thread>

#ifdef __IOSERVICE__
namespace std {

	void IoService::runPreinit()
	{
		ArchiveService& archiveService_ = Singleton<ArchiveService>::instance();
		archiveService_.m_tRunConfigure.connect(boost::bind(&IoService::runLoad, this));

		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&IoService::runInit, this));
		initService_.m_tRunStart0.connect(boost::bind(&IoService::runStart, this));
		initService_.m_tRunRun.connect(boost::bind(&IoService::runRun, this));
		initService_.m_tRunStop.connect(boost::bind(&IoService::runStop, this));
		initService_.registerArchive(this->streamUrl());
	}

	void IoService::runLoad()
	{
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("run loading ioService"));
		ArchiveService& archiveService_ = Singleton<ArchiveService>::instance();
		archiveService_.initUrlStream(this);
		logService_.logInfo(log_1("run load ioService finish"));
	}

	void IoService::runInit()
	{
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("init ioService"));
		for (__i32 i = 0; i < mIoServiceCount; ++i) {
			IoServicePtr ioService(new asio::io_service());
			WorkPtr work(new asio::io_service::work(*ioService));
			mIoServices.push_back(ioService);
			mWork.push_back(work);
		}
		logService_.logInfo(log_1("init ioService finish!"));
	}
	
	void IoService::runStart()
	{
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("ioService run runStart"));
		
		InitService& initService_ = Singleton<InitService>::instance();
		mSignals.reset(new asio::signal_set(this->getIoService()));
		mSignals->add(SIGINT); mSignals->add(SIGTERM);
		mSignals->async_wait(boost::bind(&InitService::runStop, &initService_));
		
		logService_.logInfo(log_1("ioService runStart finish"));
	}

	void IoService::runRun()
	{
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("run ioService"));
		vector<std::shared_ptr<std::thread>> threads;
		for (size_t i = 0; i < mIoServices.size(); ++i) {
			std::shared_ptr<std::thread> thread_(new std::thread(boost::bind(&asio::io_service::run, mIoServices[i])));
			threads.push_back(thread_);
		}
	#ifdef __RUNING__
		for (size_t i = 0; i < threads.size(); ++i) {
			threads[i]->join();
		}
	#endif
		logService_.logInfo(log_1("run ioService finish"));
	}

	void IoService::runStop()
	{
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("stop ioService"));
		for (size_t i = 0; i < mIoServices.size(); ++i) {
			mIoServices[i]->stop();
		}
		logService_.logInfo(log_1("ioService have been stoped"));
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

	const char * IoService::streamName()
	{
		return "ioService";
	}

	const char * IoService::streamUrl()
	{
	#ifdef __CLIENT__
		return "common/ioservice/config/clientIoService.xml";
	#endif
	#ifdef __SERVER__
		return "common/ioservice/config/serverIoService.xml";
	#endif 
	}

	void IoService::runClear()
	{
		mIoServices.clear();
		mWorks.clear();
		mNextIoService = 0;
		mIoServiceCount = 0;
	}

	IoService::IoService()
	{
		this->runClear();
	}

	IoService::~IoService()
	{
		this->runClear();
	}

}
#endif
