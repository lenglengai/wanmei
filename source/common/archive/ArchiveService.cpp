#include "../DefInc.h"
#include "../init/InitService.h"
#include "ArchiveService.h"

#ifdef __ARCHIVE__
namespace std {

	const char * ArchiveService::streamName()
	{
		return "archiveService";
	}

	const char * ArchiveService::streamUrl()
	{
		return "archive.xml";
	}

	void ArchiveService::switchJourney(__i16 nJourney)
	{
		if (mJourney == nJourney) return;
		if (0 != mJourney) {
			mArchiveReader.runClose();
		}
		mJourney = nJourney; std::string journey_ = "journey_";
		journey_ += __convert<std::string, __i16>(nJourney);
		mArchiveReader.runOpen(journey_.c_str());
	}

	void ArchiveService::runLoad()
	{
		std::string configure_ = "configure.jf";
		mConfigure.runOpen(configure_.c_str());
	}

	void ArchiveService::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunLoad0.connect(boost::bind(&ArchiveService::runLoad, this));
	}

	ArchiveService::ArchiveService()
		: mJourney(0)
	{
	}

	ArchiveService::~ArchiveService()
	{
		mJourney = 0;
	}

}
#endif
