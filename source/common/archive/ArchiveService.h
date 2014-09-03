#pragma once

#include "ArchiveReader.h"

#ifdef __ARCHIVE__
namespace std {

	class __funapi ArchiveService : boost::noncopyable
	{
	public:
		template<class T>
		void initUrlStream(T * nUrlStream)
		{
			char * nBuf = nullptr; __i32 nSize = 0;
			const char * streamUrl_ = nUrlStream->streamUrl();
			const char * streamName_ = nUrlStream->streamName();
			if (!mArchiveReader.readKey(streamUrl_, &nBuf, &nSize)) {
				return;
			}
			XmlReader xmlReader_;
			xmlReader_.openStr(nBuf);
			xmlReader_.selectStream(streamName_);
			nUrlStream->headSerialize(xmlReader_);
			xmlReader_.runClose();
		}
		
		boost::signals2::signal<void()> m_tRunJourney;
		void loadJourney(__i16 nJourney);
		
		void runPreinit();

		boost::signals2::signal<void()> m_tRunConfigure;
		void runLoad();

	private:
		void runClear();

	public:
		ArchiveService();
		~ArchiveService();

	private:
		ArchiveReader mArchiveReader;
		std::set<__i16> mJourneys;
	};

}
#endif
