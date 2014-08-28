#include "../DefInc.h"
#include "JourneyDescripter.h"

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

	__i32 JourneyDescripter::getJourney()
	{
		return mJourney;
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