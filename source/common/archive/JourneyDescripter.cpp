#include "../DefInc.h"

namespace std {

		std::list<std::string>& JourneyDescripter::getJourneys()
		{
			return mJourneys;
		}

		std::string& JourneyDescripter::getJourney()
		{
			return mJourney;
		}

		JourneyDescripter::JourneyDescripter()
			: mJourney("")
		{
			mJourneys.clear();
		}

		JourneyDescripter::~JourneyDescripter()
		{
			mJourneys.clear();
			mJourney = "";
		}

}
