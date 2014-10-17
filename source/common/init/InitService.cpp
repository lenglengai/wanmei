#include "../Common.h"

namespace std {

	bool InitService::runPreinit(bool nConfigure)
	{
		if (mInitType > InitType_::mNone_) return false;
		mConfigure = nConfigure;

#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		if (!logService_.runPreinit()) return false;
#endif
		PreinitSlot& preinitSlot = Singleton<PreinitSlot>::instance();
		preinitSlot.runPreinit();

		mInitType = InitType_::mPreinit_;
		return true;
	}
	
    void InitService::registerArchive(const char * nArchive)
    {
        if (false == mConfigure)  return;
        auto it = mArchives.find(nArchive);
        if ( it != mArchives.end()) {
            LogService& logService_ = Singleton<LogService>::instance();
            logService_.logError(log_2("initService registerArchive fail, nArchive is ", nArchive));
            return;
        }
        mArchives.insert(nArchive);
    }

    void InitService::runConfigure()
    {
        ArchiveWriter archiveWriter;
        archiveWriter.runOpen("configure.jf");
        archiveWriter.runArchives(mArchives);
        archiveWriter.runClose();
    }

	void InitService::runLoad0()
	{
		if (InitType_::mPreinit_ != mInitType) {
	#ifdef __LOG__
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_2("InitService run runLoad0 fail: ", mInitType));
	#endif
			return;
		}
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("InitService run runLoad0!"));
	#endif
		mInitType = InitType_::mLoad0_;
		this->m_tRunLoad0();
	#ifdef __LOG__
		logService_.logInfo(log_1("InitService run runLoad0 finish!"));
	#endif
	}

	void InitService::runLoad1()
	{
		if (InitType_::mLoad0_ != mInitType) {
	#ifdef __LOG__
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_2("InitService run runLoad1 fail: ", mInitType));
	#endif
			return;
		}
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("InitService run runLoad1!"));
	#endif
		mInitType = InitType_::mLoad1_;
		this->m_tRunLoad1();
	#ifdef __LOG__
		logService_.logInfo(log_1("InitService run runLoad1 finish!"));
	#endif
	}

	void InitService::runInit0()
	{
		if (InitType_::mLoad1_ != mInitType) {
	#ifdef __LOG__
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_2("InitService run runInit0 fail: ", mInitType));
	#endif
			return;
		}
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("InitService run runInit0!"));
	#endif
		mInitType = InitType_::mInit0_;
		this->m_tRunInit0();
	#ifdef __LOG__
		logService_.logInfo(log_1("InitService run runInit0 finish!"));
	#endif
	}

	void InitService::runInit1()
	{
		if (InitType_::mInit0_ != mInitType) {
	#ifdef __LOG__
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_2("InitService run runInit1 fail: ", mInitType));
	#endif
			return;
		}
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("InitService run runInit1!"));
	#endif
		mInitType = InitType_::mInit1_;
		this->m_tRunInit1();
	#ifdef __LOG__
		logService_.logInfo(log_1("InitService run runInit1 finish!"));
	#endif
	}

	void InitService::runStart0()
	{
		if (InitType_::mInit1_ != mInitType) {
	#ifdef __LOG__
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_2("InitService run runStart0 fail: ", mInitType));
	#endif
			return;
		}
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("InitService run runStart0!"));
	#endif
		mInitType = InitType_::mStart0_;
		this->m_tRunStart0();
	#ifdef __LOG__
		logService_.logInfo(log_1("InitService run runStart0 finish!"));
	#endif
	}

	void InitService::runStart1()
	{
		if (InitType_::mStart0_ != mInitType) {
	#ifdef __LOG__
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_2("InitService run runStart1 fail: ", mInitType));
	#endif
			return;
		}
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("InitService run runStart1!"));
	#endif
		mInitType = InitType_::mStart1_;
		this->m_tRunStart1();
	#ifdef __LOG__
		logService_.logInfo(log_1("InitService run runStart1 finish!"));
	#endif
	}

	void InitService::runRun()
	{
		if (InitType_::mStart1_ != mInitType) {
	#ifdef __LOG__
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_2("InitService run runRun fail: ", mInitType));
	#endif
			return;
		}
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("InitService run runRun!"));
	#endif
		mInitType = InitType_::mRun_;
		this->m_tRunRun();
	#ifdef __LOG__
		logService_.logInfo(log_1("InitService run runRun finish!"));
	#endif
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
	#ifdef __LOG__
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_2("InitService run runStop fail: ", mInitType));
	#endif
			return;
		}
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("InitService run runStop!"));
	#endif
		mInitType = InitType_::mStop_;
		this->m_tRunStop();
	#ifdef __LOG__
		logService_.logInfo(log_1("InitService run runStop finish!"));
	#endif
	}

	void InitService::runSave()
	{
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("InitService run runSave!"));
	#endif
		PROFILER_UPDATE();
		PROFILER_OUTPUT("profile.prof");
		this->m_tRunSave();
	#ifdef __LOG__
		logService_.logInfo(log_1("InitService run runSave sucess!"));
	#endif
	}

	void InitService::runExit()
	{
		if (InitType_::mStop_ != mInitType) {
	#ifdef __LOG__
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_2("InitService run runExit fail: ", mInitType));
	#endif
			return;
		}
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("InitService run runExit!"));
	#endif
		mInitType = InitType_::mExit_;
		this->m_tRunExit();
	#ifdef __LOG__
		logService_.logInfo(log_1("initService run runExit finish!"));
	#endif
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
	{
		this->runClear();
	}

	InitService::~InitService()
	{
		this->runClear();
	}

}
