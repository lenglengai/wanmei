#pragma once

#ifdef __ARCHIVE__
namespace std {

	class JourneyDescripter : boost::noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize)
		{
			nSerialize.runInt32(mJourney, "journeyId");
			nSerialize.runInt32(mJourneyName, "journeyName");
			nSerialize.runStrings(mJourneys, "journeys", "journey");
		}
		const char * streamName();
		const char * streamUrl();

		std::list<std::string>& getJourneys();
		std::string& getJourneyName();
		__i32 getJourney();

		JourneyDescripter();
		~JourneyDescripter();

	private:
		std::list<std::string> mJourneys;
		std::string mJourneyName;
		__i32 mJourney;
	};

}
#endif
