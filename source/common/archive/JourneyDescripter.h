#pragma once

namespace std {

	class JourneyDescripter
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize)
		{
			nSerialize.runString(mJourney, "journey");
			nSerialize.runStreamsCount(mJourneys, "journeys", "journey", mJourneys.size());
		}

		std::list<std::string>& getJourneys();
		std::string& getJourney();

		JourneyDescripter();
		~JourneyDescripter();

	private:
		std::list<std::string> mJourneys;
		std::string mJourney;
	};

}
