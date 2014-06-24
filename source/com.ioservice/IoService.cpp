#include "../com.common/DefInc.h"
#include "../com.setting/SettingService.h"
#include "../com.log/LogService.h"
#include "../com.init/InitService.h"
#include "IoService.h"

namespace std {

	void IoService::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunLoad.connect(boost::bind(&IoService::runLoad, this));
		initService_.m_tRunStart.connect(boost::bind(&IoService::runStart, this));
		initService_.m_tRunInit.connect(boost::bind(&IoService::runInit, this));
		initService_.m_tRunRun.connect(boost::bind(&IoService::runRun, this));
		initService_.m_tRunStop.connect(boost::bind(&IoService::runStop, this));
	}

	void IoService::runLoad()
	{
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("加载IO服务"));
		SettingService& settingService_ = Singleton<SettingService>::instance();
		settingService_.initUrlStream(this);
	}

	void IoService::runStart()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		mSignals.reset(new asio::signal_set(this->getIoService()));
		mSignals->add(SIGINT);
		mSignals->add(SIGTERM);
		mSignals->async_wait(boost::bind(&InitService::runStop, &initService_));
	}

	void IoService::runInit()
	{
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("初始化IO服务"));
		for (__i32 i = 0; i < mIoServiceCount; ++i) {
			IoServicePtr ioService(new asio::io_service());
			WorkPtr work(new asio::io_service::work(*ioService));
			mIoServices.push_back(ioService);
			mWork.push_back(work);
		}
	}

	void IoService::runRun()
	{
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("运行IO服务"));
		vector<shared_ptr<boost::thread>> threads;
		for (size_t i = 0; i < mIoServices.size(); ++i) {
			shared_ptr<boost::thread> thread_(new boost::thread(boost::bind(&asio::io_service::run, mIoServices[i])));
			threads.push_back(thread_);
		}
		for (size_t i = 0; i < threads.size(); ++i) {
			threads[i]->join();
		}
	}

	void IoService::runStop()
	{
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("停止IO服务"));
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
		return "config/ioService.xml";
	}

	IoService::IoService()
		: mNextIoService(0)
	{
	}

	IoService::~IoService()
	{
		mNextIoService = 0;
	}

}
