#include "../DefInc.h"
#include "ArchiveService.h"

#ifdef __ARCHIVE__
namespace std {

	const char * ArchiveService::streamName()
	{
		return "archiveService";
	}

	const char * ArchiveService::streamUrl()
	{
		return "config/archive.xml";
	}

	void ArchiveService::switchJourney(__i16 nJourney)
	{
		if (mJourney == nJourney) return;
		mJourney = nJourney; std::string journey_ = "journey_";
		journey_ += __convert<std::string, __i16>(nJourney);
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
