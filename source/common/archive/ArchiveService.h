#pragma once

#include "JourneyDescripter.h"
#include "ArchiveReader.h"
#include "XmlReader.h"

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
		
		template<class T>
		void xmlUrlStream(T * nUrlStream)
		{
			XmlReader xmlReader_;
			xmlReader_.openUrl(nUrlStream->streamUrl());
			xmlReader_.selectStream(nUrlStream->streamName());
			nUrlStream->headSerialize(xmlReader_);
			xmlReader_.runClose();
		}
		
		void loadJourney(__i32 nJourneyId);
		void runPreinit();

		boost::signals2::signal<void()> m_tRunConfigure;
		void runLoad();

	private:
		void runJourney(std::string& nJourneyName);
		void runJourneyDescriptor();
		void runClear();

	public:
		ArchiveService();
		~ArchiveService();

	private:
		std::map<std::string, IJourney *> mJourneys;
		ArchiveReader mArchiveReader;
		std::set<__i32> mJourneyIds;
	};

}
#endif
