#include "../../include/Include.h"

namespace std {

	std::string& JourneyKey::getJourneyId()
	{
		return mJourneyId;
	}
	
	std::string& JourneyKey::getFileName()
	{
		return mFileName;
	}

	JourneyKey::JourneyKey()
		: mJourneyId("")
		, mFileName("")
	{
	}
	
	JourneyKey::~JourneyKey()
	{
		mJourneyId = "";
		mFileName = "";
	}

}
