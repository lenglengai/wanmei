#include "../Common.h"

#ifdef __ARCHIVE__
namespace std {

	void ArchiveService::loadJourney(__i32 nJourneyId)
	{
		auto it = mJourneyIds.find(nJourneyId);
		if (it == mJourneyIds.end()) return;
		std::string journey_ = "journey_";
		journey_ += __convert<std::string, __i32>(nJourneyId);
		journey_ += ".jf";
		mArchiveReader.runOpen(journey_.c_str());
		this->runJourneyDescriptor();
		mArchiveReader.runClose();
	}
	
	void ArchiveService::runJourneyDescriptor()
	{
		JourneyDescripter journeyDescripter;
		this->initUrlStream(&journeyDescripter);
		std::list<std::string>& journeys = journeyDescripter.getJourneys();
		std::list<std::string>::iterator it = journeys.begin();
		for ( ; it != journeys.end(); ++it ) {
			this->runJourney(*it);
		}
	}
	
	void ArchiveService::runJourney(std::string& nJourneyName)
	{
		std::map<std::string, IJourney *> it = mJourneys.find(nJourneyName);
		if (it == mJourneys.end()) {
			LogService logService_ = Singleton<LogService>::instance();
			logService_.logError(log_2("ArchiveService runJourney nJourneyName is:!", nJourneyName));
			return;
		}
		IJourney * journey_ = it->second;
		journey_.loadJourney();
	]

	bool ArchiveService::runPreinit()
	{
		LogService logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("ArchiveService run runPreinit!"));
		
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunLoad0.connect(boost::bind(&ArchiveService::runLoad, this));
		
		logService_.logInfo(log_1("ArchiveService run runPreinit finish!"));
		return true;
	}
	
	void ArchiveService::runLoad()
	{
		LogService logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("ArchiveService run runLoad!"));
		
		std::string configure_ = "configure.jf";
		mArchiveReader.runOpen(configure_.c_str());
		this->m_tRunConfigure();
		mArchiveReader.runClose();
		
		logService_.logInfo(log_1("ArchiveService run runLoad finish!"));
	}

	void ArchiveService::runClear()
	{
		m_tRunConfigure.disconnect_all_slots();
		mJourneys.clear();
	}

	ArchiveService::ArchiveService()
	{
		this->runClear();
	}

	ArchiveService::~ArchiveService()
	{
		this->runClear();
	}

}
#endif
