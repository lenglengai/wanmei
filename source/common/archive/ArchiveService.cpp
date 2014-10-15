#include "../Common.h"

#include "JourneyDescripter.h"

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
		auto it = mJourneys.find(nJourneyName);
		if (it == mJourneys.end()) {
		#ifdef __LOG__
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_2("ArchiveService runJourney nJourneyName is:!", nJourneyName));
		#endif
		return;
		}
		IJourney * journey_ = it->second;
		journey_->loadJourney();
	}

	bool ArchiveService::runPreinit()
	{
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("ArchiveService run runPreinit!"));
	#endif
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunLoad0.connect(boost::bind(&ArchiveService::runLoad, this));
	#ifdef __LOG__
		logService_.logInfo(log_1("ArchiveService run runPreinit finish!"));
	#endif
		return true;
	}
	
	void ArchiveService::runLoad()
	{
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("ArchiveService run runLoad!"));
	#endif
		std::string configure_ = "configure.jf";
		mArchiveReader.runOpen(configure_.c_str());
		this->m_tRunConfigure();
		mArchiveReader.runClose();
	#ifdef __LOG__
		logService_.logInfo(log_1("ArchiveService run runLoad finish!"));
	#endif
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
	
	static Preinit<ArchiveService> sArchiveServicePreinit;

}
#endif
