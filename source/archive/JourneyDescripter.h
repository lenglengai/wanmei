#pragma once

namespace std {

	class JourneyDescripter : boost::noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize)
		{
			nSerialize.runStreamsCount(mJourneyKeys, "journeyKeys", "journeyKey");
		}
		const char * streamName();
		const char * streamUrl();

		std::list<JourneyKeyPtr>& getJourneyKeys();

		JourneyDescripter();
		~JourneyDescripter();

	private:
		std::list<JourneyKeyPtr> mJourneyKeys;
	};

}
