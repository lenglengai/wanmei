#include "../DefInc.h"
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
	
	std::string& JourneyDescripter::getJourneyName()
	{
		return mJourneyName;
	}

	__i32 JourneyDescripter::getJourney()
	{
		return mJourney;
	}

	JourneyDescripter::JourneyDescripter()
		: mJourneyName("")
		, mJourney(0)
	{
		mJourneys.clear();
	}

	JourneyDescripter::~JourneyDescripter()
	{
		mJourneys.clear();
		mJourneyName = "";
		mJourney = 0;
	}

}
#endif
