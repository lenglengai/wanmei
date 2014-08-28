#pragma once

#include "ArchiveReader.h"

namespace std {

	class __funapi ArchiveService : boost::noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize)
		{
#ifdef __CLIENT__
			nSerialize.runInt16(mJourney, "journey");
#endif // 
		}
		const char * streamName();
		const char * streamUrl();

		void switchJourney(__i16 nJourney);

	public:
		ArchiveService();
		~ArchiveService();

	private:
		ArchiveReader mArchiveReader;
		__i16 mJourney;
	};

}