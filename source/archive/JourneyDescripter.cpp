#include "../../include/Include.h"

namespace std {

	const char * JourneyDescripter::streamName()
	{
		return "journeyDescripter";
	}

	const char * JourneyDescripter::streamUrl()
	{
		return "journeyDescripter.xml";
	}

	std::list<JourneyKeyPtr>& JourneyDescripter::getJourneyKeys()
	{
		return mJourneyKeys;
	}
	
	JourneyDescripter::JourneyDescripter()
	{
		mJourneyKeys.clear();
	}

	JourneyDescripter::~JourneyDescripter()
	{
		mJourneyKeys.clear();
	}

}
