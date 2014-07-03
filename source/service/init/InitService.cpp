#include "../../common/DefInc.h"

#include "../log/LogService.h"
#include "../time/TimeService.h"
#include "../random/RandomService.h"
#include "../crc/CrcService.h"

#include "../setting/SettingService.h"
#include "../handle/HandleService.h"
#include "../ioservice/IoService.h"

#include "../../net/packet/ProtocolService.h"
#include "../../logic/ping/PingService.h"

#include "../../net/server/Server.h"
#include "../../net/client/Client.h"

#include "InitService.h"

namespace std {

	void InitService::runPreinit(const string& nPath)
	{
		if (mInitType > InitType_::mNone_) return;

		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.runPreinit();
		TimeService& timeService_ = Singleton<TimeService>::instance();
		timeService_.runPreinit();
		RandomService& randomService_ = Singleton<RandomService>::instance();
		randomService_.runPreinit();
		CrcService& crcService_ = Singleton<CrcService>::instance();
		crcService_.runPreinit();


		SettingService& settingService_ = Singleton<SettingService>::instance();
		settingService_.runPreinit("");
		HandleService& handleService_ = Singleton<HandleService>::instance();
		handleService_.runPreinit();
		IoService& ioService_ = Singleton<IoService>::instance();
		ioService_.runPreinit();
		

		ProtocolService& protocolService_ = Singleton<ProtocolService>::instance();
		protocolService_.runPreinit();
		PingProtocol& pingProtocol_ = Singleton<PingProtocol>::instance();
		pingProtocol_.runPreinit();


	#ifdef __SERVER__
		Server& server_ = Singleton<Server>::instance();
		server_.runPreinit();
	#endif
	#ifdef __CLIENT__
		Client& client_ = Singleton<Client>::instance();
		client_.runPreinit();
	#endif

		mInitType = InitType_::mPreinit_;
	}

	void InitService::runLoad()
	{
		if (InitType_::mPreinit_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("initService load fail, initType is ", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("initService run load!"));
		mInitType = InitType_::mLoad_;
		this->m_tRunLoad();
	}

	void InitService::runInit()
	{
		if (InitType_::mLoad_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("initService init fail, initType is ", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("initService run init!"));
		mInitType = InitType_::mInit_;
		this->m_tRunInit();
	}

	void InitService::runStart()
	{
		if (InitType_::mInit_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("initService start fail, initType is ", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("initService run start!"));
		mInitType = InitType_::mStart_;
		this->m_tRunStart();
	}

	void InitService::runRun()
	{
		if (InitType_::mStart_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("initService run fail, initType is ", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("initService is running!"));
		mInitType = InitType_::mRun_;
		this->m_tRunRun();
	}

	void InitService::runPause(bool nPause)
	{
		if (nPause) {
			mInitType = InitType_::mPause_;
		} else {
			mInitType = InitType_::mRun_;
		}
	}

	bool InitService::isPause()
	{
		return (InitType_::mPause_ == mInitType);
	}

	void InitService::runStop()
	{
		if (InitType_::mRun_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("initService stop fail, initType is ", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("initService is stopped!"));
		mInitType = InitType_::mStop_;
		this->m_tRunStop();
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

	void InitService::runExit()
	{
		if (InitType_::mStop_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("initService exit fail, initType is ", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("initService is exited!"));
		mInitType = InitType_::mExit_;
		this->m_tRunExit();	
		loginService_.logInfo(log_1("initService exit sucess!"));
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
		mInitType = InitType_::mNone_;
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
