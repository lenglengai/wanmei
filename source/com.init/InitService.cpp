#include "../com.common/DefInc.h"
#include "../com.log/LogService.h"
#include "InitService.h"


namespace std {

	void InitService::runPreinit(const string& nPath)
	{
		if (mInitType > mInitTypeNone_) return;
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.runPreinit();
		mInitType = mInitTypePreinit_;
	}

	void InitService::runLoad()
	{
		if (mInitTypePreinit_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logInfo(log_2("InitService runload error!", mInitType));
			return;
		}
		mInitType = mInitTypeLoad_;
		this->m_tRunLoad();
	}

	void InitService::runInit()
	{
		if (mInitTypeLoad_ != mInitType) {
			return;
		}
		mInitType = mInitTypeInit_;
		this->m_tRunInit();
	}

	void InitService::runStart()
	{
		if (mInitTypeInit_ != mInitType) {
			return;
		}
		mInitType = mInitTypeStart_;
		this->m_tRunStart();
	}

	void InitService::runRun()
	{
		if (mInitTypeStart_ != mInitType) {
			return;
		}
		mInitType = mInitTypeRun_;
		this->m_tRunRun();
	}

	void InitService::runStop()
	{
		if (mInitTypeRun_ != mInitType) {
			return;
		}
		mInitType = mInitTypeStop_;
		this->m_tRunStop();
	}

	void InitService::runExit()
	{
		if (mInitTypeStop_ != mInitType) {
			return;
		}
		mInitType = mInitTypeExit_;
		this->m_tRunExit();
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
		this->runClear();
	}

	InitService::~InitService()
	{
		this->runClear();
	}

}
