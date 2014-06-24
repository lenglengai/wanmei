#include "../com.common/DefInc.h"
#include "../com.log/LogService.h"
#include "../com.crc/CrcService.h"
#include "../com.setting/SettingService.h"
#include "../com.handle/HandleService.h"
#include "../com.ioservice/IoService.h"
#include "InitService.h"

namespace std {

	void InitService::runPreinit(const string& nPath)
	{
		if (mInitType > mInitTypeNone_) return;
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.runPreinit();
		CrcService& crcService_ = Singleton<CrcService>::instance();
		crcService_.runPreinit();
		SettingService& settingService_ = Singleton<SettingService>::instance();
		settingService_.runPreinit("");
		HandleService& handleService_ = Singleton<HandleService>::instance();
		handleService_.runPreinit();
		IoService& ioService_ = Singleton<IoService>::instance();
		ioService_.runPreinit();
		mInitType = mInitTypePreinit_;
	}

	void InitService::runLoad()
	{
		if (mInitTypePreinit_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("initService load fail, initType is ", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("initService run load!"));
		mInitType = mInitTypeLoad_;
		this->m_tRunLoad();
	}

	void InitService::runInit()
	{
		if (mInitTypeLoad_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("initService init fail, initType is ", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("initService run init!"));
		mInitType = mInitTypeInit_;
		this->m_tRunInit();
	}

	void InitService::runStart()
	{
		if (mInitTypeInit_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("initService start fail, initType is ", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("initService run start!"));
		mInitType = mInitTypeStart_;
		this->m_tRunStart();
	}

	void InitService::runRun()
	{
		if (mInitTypeStart_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("initService run fail, initType is ", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("initService is running!"));
		mInitType = mInitTypeRun_;
		this->m_tRunRun();
	}

	void InitService::runStop()
	{
		if (mInitTypeRun_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("initService stop fail, initType is ", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("initService is stopped!"));
		mInitType = mInitTypeStop_;
		this->m_tRunStop();
	}

	void InitService::runExit()
	{
		if (mInitTypeStop_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("initService exit fail, initType is ", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("initService is exited!"));
		mInitType = mInitTypeExit_;
		this->m_tRunExit();	
		loginService_.logInfo(log_1("initService exit sucess!"));
	}

	void InitService::runSave()
	{
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("initService save data!"));
		PROFILER_UPDATE();
		PROFILER_OUTPUT("profile.prof");
		this->m_tRunSave();	
		loginService_.logInfo(log_1("initService save data sucess!"));
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
