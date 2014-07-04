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

	void InitService::runLoad0()
	{
		if (InitType_::mPreinit_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("initService load0 fail, initType is ", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("initService run load0!"));
		mInitType = InitType_::mLoad0_;
		this->m_tRunLoad0();
	}

	void InitService::runLoad1()
	{
		if (InitType_::mLoad0_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("initService load1 fail, initType is ", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("initService run load1!"));
		mInitType = InitType_::mLoad1_;
		this->m_tRunLoad1();
	}

	void InitService::runInit0()
	{
		if (InitType_::mLoad1_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("initService init0 fail, initType is ", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("initService run init0!"));
		mInitType = InitType_::mInit0_;
		this->m_tRunInit0();
	}

	void InitService::runInit1()
	{
		if (InitType_::mInit0_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("initService init1 fail, initType is ", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("initService run init1!"));
		mInitType = InitType_::mInit1_;
		this->m_tRunInit1();
	}

	void InitService::runStart0()
	{
		if (InitType_::mInit1_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("initService start0 fail, initType is ", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("initService run start0!"));
		mInitType = InitType_::mStart0_;
		this->m_tRunStart0();
	}

	void InitService::runStart1()
	{
		if (InitType_::mStart0_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("initService start1 fail, initType is ", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("initService run start1!"));
		mInitType = InitType_::mStart1_;
		this->m_tRunStart1();
	}

	void InitService::runRun0()
	{
		if (InitType_::mStart1_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("initService run0 fail, initType is ", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("initService is running0!"));
		mInitType = InitType_::mRun0_;
		this->m_tRunRun0();
	}

	void InitService::runRun1()
	{
		if (InitType_::mRun0_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("initService run1 fail, initType is ", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("initService is running1!"));
		mInitType = InitType_::mRun1_;
		this->m_tRunRun1();
	}

	void InitService::runPause(bool nPause)
	{
		if (nPause) {
			mInitType = InitType_::mPause_;
		} else {
			mInitType = InitType_::mRun1_;
		}
	}

	bool InitService::isPause()
	{
		return (InitType_::mPause_ == mInitType);
	}

	void InitService::runStop()
	{
		if (InitType_::mRun1_ != mInitType) {
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
		m_tRunLoad0.disconnect_all_slots();
		m_tRunLoad1.disconnect_all_slots();
		m_tRunInit0.disconnect_all_slots();
		m_tRunInit1.disconnect_all_slots();
		m_tRunStart0.disconnect_all_slots();
		m_tRunStart1.disconnect_all_slots();
		m_tRunRun0.disconnect_all_slots();
		m_tRunRun1.disconnect_all_slots();
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
