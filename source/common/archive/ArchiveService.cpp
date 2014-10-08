#include "../Common.h"

#ifdef __ARCHIVE__
namespace std {

	void ArchiveService::loadJourney(__i16 nJourney)
	{
		auto it = mJourneys.find(nJourney);
		if (it == mJourneys.end()) return;
		std::string journey_ = "journey_";
		journey_ += __convert<std::string, __i16>(nJourney);
		mArchiveReader.runOpen(journey_.c_str());
		this->m_tRunJourney();
		mArchiveReader.runClose();
	}

	void ArchiveService::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunLoad0.connect(boost::bind(&ArchiveService::runLoad, this));
	}
	
	void ArchiveService::runLoad()
	{
		std::string configure_ = "configure.jf";
		mArchiveReader.runOpen(configure_.c_str());
		this->m_tRunConfigure();
		mArchiveReader.runClose();
	}

	void ArchiveService::runClear()
	{
		m_tRunConfigure.disconnect_all_slots();
		m_tRunJourney.disconnect_all_slots();
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
