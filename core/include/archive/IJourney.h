#pragma once

namespace std {
	
	class IJourney : boost::noncopyable
	{
	public:
		virtual void loadJourney(__i32 nJourneyId, const char * nFileName) = 0;
		virtual const char * journeyName() = 0;
	};
	
}
