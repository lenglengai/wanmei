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
			loginService_.logError(log_2("加载资源失败,初始化类型为!", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("开始加载资源"));
		mInitType = mInitTypeLoad_;
		this->m_tRunLoad();
	}

	void InitService::runInit()
	{
		if (mInitTypeLoad_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("初始化失败,初始化类型为!", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("程序初始化"));
		mInitType = mInitTypeInit_;
		this->m_tRunInit();
	}

	void InitService::runStart()
	{
		if (mInitTypeInit_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("启动失败,初始化类型为!", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("启动程序"));
		mInitType = mInitTypeStart_;
		this->m_tRunStart();
	}

	void InitService::runRun()
	{
		if (mInitTypeStart_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("运行失败,初始化类型为!", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("程序运行"));
		mInitType = mInitTypeRun_;
		this->m_tRunRun();
	}

	void InitService::runStop()
	{
		if (mInitTypeRun_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("停止失败,初始化类型为!", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("程序停止"));
		mInitType = mInitTypeStop_;
		this->m_tRunStop();
	}

	void InitService::runExit()
	{
		if (mInitTypeStop_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("程序退出失败,初始化类型为!", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("程序退出"));
		mInitType = mInitTypeExit_;
		this->m_tRunExit();	
		loginService_.logInfo(log_1("退出成功!"));
	}

	void InitService::runSave()
	{
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("保存数据"));
		PROFILER_UPDATE();
		PROFILER_OUTPUT("profile.prof");
		this->m_tRunSave();	
		loginService_.logInfo(log_1("数据保存成功!"));
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
