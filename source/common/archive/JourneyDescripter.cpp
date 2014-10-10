#include "../Common.h"
#include "JourneyDescripter.h"

#ifdef __ARCHIVE__
namespace std {

	const char * JourneyDescripter::streamName()
	{
		return "journeyDescripter";
	}

	const char * JourneyDescripter::streamUrl()
	{
		return "journeyDescripter.xml";
	}

	std::list<std::string>& JourneyDescripter::getJourneys()
	{
		return mJourneys;
	}
	
	__i32 JourneyDescripter::getJourneyId()
	{
		return mJourneyId;
	}

	JourneyDescripter::JourneyDescripter()
		: mJourney(0)
	{
		mJourneys.clear();
	}

	JourneyDescripter::~JourneyDescripter()
	{
		mJourneys.clear();
		mJourney = 0;
	}

}
#endif
