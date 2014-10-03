#include "../DefInc.h"

#include "../crc/CrcService.h"
#include "../log/LogService.h"
#include "../time/TimeService.h"
#include "../random/RandomService.h"
#include "../compress/CompressService.h"

#include "../setting/SettingService.h"
#include "../archive/ArchiveService.h"

#include "../handle/HandleService.h"
#include "../ioservice/IoService.h"

 #include "../net/ProtocolService.h"
 #include "../net/Server.h"
 #include "../net/Client.h"
 
 #include "../../logic/ping/PingService.h"

#include "InitService.h"

namespace std {

	void InitService::runPreinit(const char * nPath, bool nConfigure)
	{
		if (mInitType > InitType_::mNone_) return;
		mConfigure = nConfigure;
		
#ifdef __LOG__
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.runPreinit();
#endif
#ifdef __WITHTIME__
		TimeService& timeService_ = Singleton<TimeService>::instance();
		timeService_.runPreinit();
#endif
#ifdef __RANDOM__
		RandomService& randomService_ = Singleton<RandomService>::instance();
		randomService_.runPreinit();
#endif
#ifdef __CRC__
		CrcService& crcService_ = Singleton<CrcService>::instance();
		crcService_.runPreinit();
#endif
#ifdef __COMPRESS__
		CompressService& compressService_ = Singleton<CompressService>::instance();
		compressService_.runPreinit();
#endif
	
#ifdef __SETTING__
		SettingService& settingService_ = Singleton<SettingService>::instance();
		settingService_.runPreinit(nPath);
#endif
#ifdef __ARCHIVE__
		ArchiveService& archiveService_ = Singleton<ArchiveService>::instance();
		archiveService_.runPreinit();
#endif

#ifdef __HANDLE__
		HandleService& handleService_ = Singleton<HandleService>::instance();
		handleService_.runPreinit();
#endif
#ifdef __IOSERVICE__
		IoService& ioService_ = Singleton<IoService>::instance();
		ioService_.runPreinit();
#endif
#ifdef __PING__
		ProtocolService& protocolService_ = Singleton<ProtocolService>::instance();
		protocolService_.runPreinit();
		PingProtocol& pingProtocol_ = Singleton<PingProtocol>::instance();
		pingProtocol_.runPreinit();
#endif

#ifdef __SERVERNET__
		Server& server_ = Singleton<Server>::instance();
		server_.runPreinit();
#endif
#ifdef __CLIENTNET__
		Client& client_ = Singleton<Client>::instance();
		client_.runPreinit();
#endif

		mInitType = InitType_::mPreinit_;
	}
	
	void InitService::registerArchive(const char * nArchive)
	{
		if (false == mConfigure)  return;
		auto it = mArchives.find(nArchive);
		if ( it != strings.end()) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("initService registerArchive fail, nArchive is ", nArchive));
			return;
		}
		mArchives.insert(nArchive);
	}

	void InitService::runConfigure()
	{
		ArchiveWriter archiveWriter;
		archiveWriter.openUrl("configure.jf");
		archiveWriter.runArchives(mArchives);
		archiveWriter.runClose();
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

	void InitService::runRun()
	{
		if (InitType_::mStart1_ != mInitType) {
			LogService& loginService_ = Singleton<LogService>::instance();
			loginService_.logError(log_2("initService run0 fail, initType is ", mInitType));
			return;
		}
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("initService is running0!"));
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
		m_tRunLoad0.disconnect_all_slots();
		m_tRunLoad1.disconnect_all_slots();
		m_tRunInit0.disconnect_all_slots();
		m_tRunInit1.disconnect_all_slots();
		m_tRunStart0.disconnect_all_slots();
		m_tRunStart1.disconnect_all_slots();
		m_tRunRun.disconnect_all_slots();
		m_tRunStop.disconnect_all_slots();
		m_tRunSave.disconnect_all_slots();
		m_tRunExit.disconnect_all_slots();
		mInitType = InitType_::mNone_;
		mConfigure = false;
		mArchives.clear();
	}

	InitService::InitService()
		: mInitType(InitType_::mNone_)
	{
		this->runClear();
	}

	InitService::~InitService()
	{
		this->runClear();
	}

}
