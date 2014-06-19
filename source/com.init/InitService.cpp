#include "Include.h"

namespace std {

	void InitService::runPreinit(const string& nPath)
	{
		if (mInitType > mInitTypeNone_) return;
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.runPreinit();
		CrcService& crcService = Singleton<CrcService>::instance();
		crcService.runPreinit();
		SettingService& settingService_ = Singleton<SettingService>::instance();
		settingService_.runPreinit(nPath);
		HandleService& handleService_ = Singleton<HandleService>::instance();
		handleService_.runPreinit();
		IoService& ioService_ = Singleton<IoService>::instance();
		ioService_.runPreinit();
		Server& server_ = Singleton<Server>::instance();
		server_.runPreinit();
		mPreinited = true;
	}

	void InitService::runInit()
	{
		//PROFILE_FUNC()
		if (mInited) return;
		this->m_tRunInit();
		mInited = true;
	}

	void InitService::runStart()
	{
		if (mStarted) return;
		IoService& ioService_ = Singleton<IoService>::instance();
		mSignals.reset(new asio::signal_set(ioService_.getIoService()));
		mSignals->add(SIGINT);
		mSignals->add(SIGTERM);
		mSignals->async_wait(boost::bind(&InitService::runStop, this));
		this->m_tRunStart();
		mStarted = true;
	}

	void InitService::runStop()
	{
		if (false == mStarted) return;
		this->m_tRunStop();
		mStarted = false;
	}

	void InitService::runRun()
	{
		this->m_tRunRun();
	}

	void InitService::runExit()
	{
		this->m_tRunExit();
		mPreinited = false;
		mInited = false;
		mStarted = false;
	}

	void InitService::runSave()
	{
		PROFILER_UPDATE();
		PROFILER_OUTPUT("profile.prof");
		this->m_tRunSave();
	}

	void InitService::runClear()
	{
		m_tRunLoad.disconnect_all_slots();
		m_tRunInit.disconnect_all_slots();
		m_tRunStart.disconnect_all_slots();
		m_tRunRun.disconnect_all_slots();
		m_tRunStop.disconnect_all_slots();
		m_tRunSave.disconnect_all_slots();
		m_tRunExit.disconnect_all_slots();
		mInitType = mInitTypeNone_;
	}

	InitService::InitService()
	{
		this.runClear();
	}

	InitService::~InitService()
	{
		this.runClear();
	}

}
