#include "../DefInc.h"
#include "../log/LogService.h"
#include "../setting/SettingService.h"
#include "../init/InitService.h"

#include "IoService.h"

#ifdef __IOSERVICE__
namespace std {

	void IoService::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunLoad0.connect(boost::bind(&IoService::runLoad, this));
		initService_.m_tRunInit0.connect(boost::bind(&IoService::runInit, this));
		initService_.m_tRunStart0.connect(boost::bind(&IoService::runStart, this));
		initService_.m_tRunRun.connect(boost::bind(&IoService::runRun, this));
		initService_.m_tRunStop.connect(boost::bind(&IoService::runStop, this));
	}

	void IoService::runLoad()
	{
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("run loading ioService"));
		SettingService& settingService_ = Singleton<SettingService>::instance();
		settingService_.initUrlStream(this);
	}

	void IoService::runInit()
	{
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("init ioService"));
		for (__i32 i = 0; i < mIoServiceCount; ++i) {
			IoServicePtr ioService(new asio::io_service());
			WorkPtr work(new asio::io_service::work(*ioService));
			mIoServices.push_back(ioService);
			mWork.push_back(work);
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
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("run ioService"));
		vector<std::shared_ptr<std::thread>> threads;
		for (size_t i = 0; i < mIoServices.size(); ++i) {
			std::shared_ptr<std::thread> thread_(new std::thread(boost::bind(&asio::io_service::run, mIoServices[i])));
			threads.push_back(thread_);
		}
	#if (defined __SERVER__) || (defined __LOGIN__)
		for (size_t i = 0; i < threads.size(); ++i) {
			threads[i]->join();
		}
	#endif
	}

	void IoService::runStop()
	{
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("stop ioService"));
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

	const char * IoService::streamName()
	{
		return "ioService";
	}

	const char * IoService::streamUrl()
	{
	#ifdef __CLIENT__
		return "config/clientIoService.xml";
	#elif 
	#ifdef __LOGIN__
		return "config/loginIoService.xml";
	#elif 
	#ifdef __SERVER__
		return "config/serverIoService.xml";
	#elif 
	#ifdef __ANDROID__
		return "config/androidIoService.xml";
	#elif
	}

	void IoService::runClear()
	{
		mIoServices.clear();
		mWork.clear();
		mNextIoService = 0;
		mIoServiceCount = 0;
	}

	IoService::IoService()
	{
	}

	IoService::~IoService()
	{
		this->runClear();
	}

}
#endif
