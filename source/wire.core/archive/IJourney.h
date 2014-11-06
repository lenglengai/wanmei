#pragma once

#ifdef __ARCHIVE__
namespace std {
	
	class IJourney
	{
	public:
		virtual const char * journeyName() = 0;
		virtual void loadJourney() = 0;
	};
	
}
#endif
