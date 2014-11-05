#pragma once

#ifdef __ARCHIVE__
namespace std {

	class JourneyDescripter : boost::noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize)
		{
			nSerialize.runInt32(mJourneyId, "journeyId");
			nSerialize.runStrings(mJourneys, "journeys", "journey");
		}
		const char * streamName();
		const char * streamUrl();

		std::list<std::string>& getJourneys();
		__i32 getJourneyId();

		JourneyDescripter();
		~JourneyDescripter();

	private:
		std::list<std::string> mJourneys;
		__i32 mJourneyId;
	};

}
#endif
