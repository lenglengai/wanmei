#include "../../include/Include.h"

namespace std {

	bool InitService::runPreinit(bool nConfigure)
	{
		if (mInitType > InitType_::mNone_) return false;
		ArchiveService& archiveService_ = Singleton<ArchiveService>::instance();
		archiveService_.setConfigure(nConfigure);
		
		LogService& logService_ = Singleton<LogService>::instance();
		if (!logService_.runPreinit()) return false;
		
		PreinitSlot& preinitSlot = Singleton<PreinitSlot>::instance();
		preinitSlot.runPreinit();
		
		mInitType = InitType_::mPreinit_;
		return true;
	}
	
	void InitService::runConfigure()
	{
		ArchiveService& archiveService_ = Singleton<ArchiveService>::instance();
		archiveService_.runConfigure();
	}
	
	void InitService::runLoad0()
	{
		if (InitType_::mPreinit_ != mInitType) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(mInitType));
			return;
		}
		mInitType = InitType_::mLoad0_;
		this->m_tRunLoad0();
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}

	void InitService::runLoad1()
	{
		if (InitType_::mLoad0_ != mInitType) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(mInitType));
			return;
		}
		mInitType = InitType_::mLoad1_;
		this->m_tRunLoad1();
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}

	void InitService::runInit0()
	{
		if (InitType_::mLoad1_ != mInitType) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(mInitType));
			return;
		}
		mInitType = InitType_::mInit0_;
		this->m_tRunInit0();
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}

	void InitService::runInit1()
	{
		if (InitType_::mInit0_ != mInitType) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(mInitType));
			return;
		}
		mInitType = InitType_::mInit1_;
		this->m_tRunInit1();
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}

	void InitService::runStart0()
	{
		if (InitType_::mInit1_ != mInitType) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(mInitType));
			return;
		}
		mInitType = InitType_::mStart0_;
		this->m_tRunStart0();
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}

	void InitService::runStart1()
	{
		if (InitType_::mStart0_ != mInitType) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(mInitType));
			return;
		}
		mInitType = InitType_::mStart1_;
		this->m_tRunStart1();
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}

	void InitService::runRun()
	{
		if (InitType_::mStart1_ != mInitType) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(mInitType));
			return;
		}
		mInitType = InitType_::mRun_;
		this->m_tRunRun();
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
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
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(mInitType));
			return;
		}
		mInitType = InitType_::mStop_;
		this->m_tRunStop();
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}

	void InitService::runSave()
	{
		this->m_tRunSave();
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}

	void InitService::runExit()
	{
		if (InitType_::mStop_ != mInitType) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(mInitType));
			return;
		}
		mInitType = InitType_::mExit_;
		this->m_tRunExit();
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}

	void InitService::runInitDB()
	{
		this->m_tInitDB();
		this->m_tInitTable();
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
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
		m_tInitDB.disconnect_all_slots();
		m_tInitTable.disconnect_all_slots();
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
