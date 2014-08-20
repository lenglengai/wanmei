#include "../DefInc.h"

#include "ArchiveService.h"

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
		mJourney = nJourney;
		mArchiveReader
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
