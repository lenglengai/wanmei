#pragma once

namespace std {
	
	class IJourney : boost::noncopyable
	{
	public:
		virtual const char * journeyName() = 0;
		virtual void loadJourney() = 0;
	};
	
}
