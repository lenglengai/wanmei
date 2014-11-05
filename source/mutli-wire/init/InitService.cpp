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
            logService_.logError(log_1(nArchive));
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
			logService_.logError(log_1(mInitType));
	#endif
			return;
		}
		mInitType = InitType_::mLoad0_;
		this->m_tRunLoad0();
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	#endif
	}

	void InitService::runLoad1()
	{
		if (InitType_::mLoad0_ != mInitType) {
	#ifdef __LOG__
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(mInitType));
	#endif
			return;
		}
		mInitType = InitType_::mLoad1_;
		this->m_tRunLoad1();
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	#endif
	}

	void InitService::runInit0()
	{
		if (InitType_::mLoad1_ != mInitType) {
	#ifdef __LOG__
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(mInitType));
	#endif
			return;
		}
		mInitType = InitType_::mInit0_;
		this->m_tRunInit0();
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	#endif
	}

	void InitService::runInit1()
	{
		if (InitType_::mInit0_ != mInitType) {
	#ifdef __LOG__
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(mInitType));
	#endif
			return;
		}
		mInitType = InitType_::mInit1_;
		this->m_tRunInit1();
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	#endif
	}

	void InitService::runStart0()
	{
		if (InitType_::mInit1_ != mInitType) {
	#ifdef __LOG__
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(mInitType));
	#endif
			return;
		}
		mInitType = InitType_::mStart0_;
		this->m_tRunStart0();
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	#endif
	}

	void InitService::runStart1()
	{
		if (InitType_::mStart0_ != mInitType) {
	#ifdef __LOG__
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(mInitType));
	#endif
			return;
		}
		mInitType = InitType_::mStart1_;
		this->m_tRunStart1();
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	#endif
	}

	void InitService::runRun()
	{
		if (InitType_::mStart1_ != mInitType) {
	#ifdef __LOG__
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(mInitType));
	#endif
			return;
		}
		mInitType = InitType_::mRun_;
		this->m_tRunRun();
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
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
			logService_.logError(log_1(mInitType));
	#endif
			return;
		}
		mInitType = InitType_::mStop_;
		this->m_tRunStop();
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	#endif
	}

	void InitService::runSave()
	{
		PROFILER_UPDATE();
		PROFILER_OUTPUT("profile.prof");
		this->m_tRunSave();
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	#endif
	}

	void InitService::runExit()
	{
		if (InitType_::mStop_ != mInitType) {
	#ifdef __LOG__
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(mInitType));
	#endif
			return;
		}
		mInitType = InitType_::mExit_;
		this->m_tRunExit();
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
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
