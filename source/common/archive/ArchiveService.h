#pragma once

#include <boost/signals2.hpp>
#include "ArchiveReader.h"


#ifdef __ARCHIVE__
namespace std {

	class __funapi ArchiveService : boost::noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize)
		{
#ifdef __CLTRECV__
			nSerialize.runInt16(mJourney, "journey");
#endif
		}
		template<class T>
		void initConfigure(T * nUrlStream)
		{
			char * nBuf = nullptr; __i32 * nSize = 0;
			if (!mConfigure.readKey(this->streamUrl(), &nBuf, &nSize)) {
				return;
			}
			XmlReader xmlReader_;
			xmlReader_.openStr(nBuf);
			xmlReader_.selectStream(this->streamName());
			nUrlStream->headSerialize(xmlReader_);
			xmlReader_.runClose();
		}
		template<class T>
		void initJourney(T * nUrlStream)
		{
			char * nBuf = nullptr; __i32 * nSize = 0;
			if (!mArchiveReader.readKey(this->streamUrl(), &nBuf, &nSize)) {
				return;
			}
			XmlReader xmlReader_;
			xmlReader_.openStr(nBuf);
			xmlReader_.selectStream(this->streamName());
			nUrlStream->headSerialize(xmlReader_);
			xmlReader_.runClose();
		}
		const char * streamName();
		const char * streamUrl();

		void switchJourney(__i16 nJourney);
		void runPreinit();
		void runLoad();

	public:
		ArchiveService();
		~ArchiveService();

	private:
#ifdef __SEVRECV__
		map<__i32, ArchiveReader> mArchiveReaders;
#endif // __SEVRECV__
#ifdef __CLTRECV__
		ArchiveReader mArchiveReader;
		__i16 mJourney;
#endif
		ArchiveReader mConfigure;
	};

}
#endif
