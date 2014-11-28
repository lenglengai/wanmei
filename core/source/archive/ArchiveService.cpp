#include "../../include/Include.h"

namespace std {

	#define CONFIGUREFILE "configure.jf"
    void ArchiveService::registerArchive(const char * nArchive)
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

	void ArchiveService::setConfigure(bool nConfigure)
	{
		mConfigure = nConfigure;
	}
		
    void ArchiveService::runConfigure()
    {
        ArchiveWriter archiveWriter;
        archiveWriter.runOpen(CONFIGUREFILE);
        archiveWriter.runArchives(mArchives);
        archiveWriter.runClose();
    }
	
	void ArchiveService::formatJourney(const char * nJourneyId, const char * nJourneyPath)
	{
		ArchiveWriter archiveWriter;
		std::string journey = "journey_"; 
		journey += nJourneyId; journey += ".jf";
		archiveWriter.openUrl(journey.c_str());
		
		SettingService& settingService = Singleton<SettingService>::instance();
		settingService.setSystemPath(nJourneyPath);
		
		JourneyDescripter journeyDescripter;
		this->xmlUrlStream(&journeyDescripter);
		
		std::list<JourneyKeyPtr>& journeyKeys = journeyDescripter.getJourneyKeys();
		__i32 count_ = static_cast<__i32>(journeyKeys.size()); 
		count_++; archiveWriter.runCount(count_);
		archiveWriter.runArchive(journeyDescripter.streamUrl());
		for (auto it : journeyKeys) {
			archiveWriter.runArchive(it->getFileName());
		}
		archiveWriter.runClose();
	}
	
	void ArchiveService::loadJourney(__i32 nJourneyId)
	{
		auto it = mJourneyIds.find(nJourneyId);
		if (it == mJourneyIds.end()) return;
		std::string journey_ = "journey_";
		journey_ += __convert<std::string, __i32>(nJourneyId);
		journey_ += ".jf";
		if ( mArchiveReader.runOpen(journey_.c_str()) ) {
			this->runJourneyDescriptor(nJourneyId);
			mArchiveReader.runClose();
			mRelease = true;
		}
	}
	
	void ArchiveService::runJourneyDescriptor(__i32 nJourneyId)
	{
		JourneyDescripter journeyDescripter;
		this->initUrlStream(&journeyDescripter);
		std::list<JourneyKeyPtr>& journeyKeys = journeyDescripter.getJourneyKeys();
		for (auto& it : journeyKeys) {
			this->runJourney(nJourneyId, it);
		}
	}
	
	void ArchiveService::runJourney(__i32 nJourneyId, JourneyKeyPtr& nJourneyKey)
	{
		std::string& journeyId = nJourneyKey->getJourneyId();
		std::string& fileName_ = nJourneyKey->getFileName();
		CrcService& crcService_ = Singleton<CrcService>::instance();
		__i32 journeyId_ = crcService_.runCommon(journeyId.c_str());
		auto it = mJourneys.find(journeyId_);
		if (it == mJourneys.end()) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(journeyId));
			return;
		}
		IJourney * journey_ = it->second;
		journey_->loadJourney(nJourneyId, fileName_);
	}

	bool ArchiveService::runPreinit()
	{
		LogService& logService_ = Singleton<LogService>::instance();

		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunLoad0.connect(boost::bind(&ArchiveService::runLoad, this));

		logService_.logInfo(log_1("finish!"));
		return true;
	}
	
	void ArchiveService::runLoad()
	{
		if( mArchiveReader.runOpen(CONFIGUREFILE) ) {
			m_tRunConfigure();
			mArchiveReader.runClose();
			mRelease = true;
		}
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}

	void ArchiveService::runClear()
	{
		m_tRunConfigure.disconnect_all_slots();
		mConfigure = false;
		mArchives.clear();
		mJourneys.clear();
		mRelease = false;
	}

	ArchiveService::ArchiveService()
	{
		this->runClear();
	}

	ArchiveService::~ArchiveService()
	{
		this->runClear();
	}
	
	static Preinit<ArchiveService> sArchiveServicePreinit;

}

