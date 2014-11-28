#pragma once

namespace std {

	class JourneyKey : boost::noncopyable
	{
	public:
		template<class T>
		void serialize(T& nSerialize)
		{
			nSerialize.runString(mJourneyId, "journeyId");
			nSerialize.runString(mFileName, "fileName");
		}

		std::string& getJourneyId();
		std::string& getFileName();

		JourneyKey();
		~JourneyKey();

	private:
		std::string mJourneyId;
		std::string mFileName;
	};
	typedef std::shared_ptr<JourneyKey> JourneyKeyPtr;

}
