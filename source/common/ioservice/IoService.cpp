#include "../Common.h"

#include <thread>

#ifdef __IOSERVICE__
namespace std {

	bool IoService::runPreinit()
	{
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("IoService run runPreinit"));
	#endif
#if defined(__SERVER__) && defined(__WITHCPU__)
		CpuService& cpuService_ = Singleton<CpuService>::instance();
		mIoServiceCount = cpuService_.getCpuCount();
#endif
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&IoService::runInit, this));
		initService_.m_tRunStart0.connect(boost::bind(&IoService::runStart, this));
		initService_.m_tRunRun.connect(boost::bind(&IoService::runRun, this));
		initService_.m_tRunStop.connect(boost::bind(&IoService::runStop, this));
	#ifdef __LOG__
		logService_.logInfo(log_1("IoService run runPreinit finish!"));
	#endif
		return true;
	}

	void IoService::runInit()
	{
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("IoService run runInit"));
	#endif
		for (__i32 i = 0; i < mIoServiceCount; ++i) {
			IoServicePtr ioService(new asio::io_service());
			WorkPtr work(new asio::io_service::work(*ioService));
			mIoServices.push_back(ioService);
			mWorks.push_back(work);
		}
	#ifdef __LOG__
		logService_.logInfo(log_1("IoService run runInit finish"));
	#endif
	}
	
	void IoService::runStart()
	{
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("IoService run runStart"));
	#endif
		InitService& initService_ = Singleton<InitService>::instance();
		mSignals.reset(new asio::signal_set(this->getIoService()));
		mSignals->add(SIGINT); mSignals->add(SIGTERM);
		mSignals->async_wait(boost::bind(&InitService::runStop, &initService_));
	#ifdef __LOG__
		logService_.logInfo(log_1("IoService runStart finish"));
	#endif
	}

	void IoService::runRun()
	{
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("IoService runRun"));
	#endif
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
	#ifdef __LOG__
		logService_.logInfo(log_1("IoService runRun finish"));
	#endif
	}

	void IoService::runStop()
	{
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("stop ioService"));
	#endif
		for (size_t i = 0; i < mIoServices.size(); ++i) {
			mIoServices[i]->stop();
		}
	#ifdef __LOG__
		logService_.logInfo(log_1("ioService have been stoped"));
	#endif
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
		mIoServices.clear();
		mWorks.clear();
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
	
	static Preinit<IoService> sIoServicePreinit;

}
#endif
