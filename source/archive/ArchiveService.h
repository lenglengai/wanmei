#pragma once

namespace std {

	class __funapi ArchiveService : boost::noncopyable
	{
	public:
		template<class T>
		void xmlUrlStream(T * nUrlStream)
		{
			XmlReader xmlReader_;
			xmlReader_.openUrl(nUrlStream->streamUrl());
			xmlReader_.selectStream(nUrlStream->streamName());
			nUrlStream->headSerialize(xmlReader_);
			xmlReader_.runClose();
		}
		
		template<class T>
		void initUrlStream(T * nUrlStream)
		{
			if (mRelease) {
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
			} else {
				this->xmlUrlStream(nUrlStream);
			}
		}
		
		void registerArchive(const char * nArchive);
		void setConfigure(bool nConfigure);
		void runConfigure();
		
		void formatJourney(const char * nJourneyId, const char * nJourneyPath);
		void loadJourney(__i32 nJourneyId);
		
		template<class T>
		void registerJourney(T * nJourney)
		{
			CrcService& crcService_ = Singleton<CrcService>::instance();
			__i32 journeyId_ = crcService_.runClassId<T>();
			auto it = mJourneys.find(journeyId_);
			if ( it != mJourneys.end() ) {
				LogService& logService_ = Singleton<LogService>::instance();
				logService_.logError(log_1(journeyId_));
				return;
			}
			mJourneys[journeyId_] = nJourney;
		}
		
		bool runPreinit();

		boost::signals2::signal<void ()> m_tRunConfigure;
		void runLoad();

	private:
		void runJourney(__i32 nJourneyId, JourneyKeyPtr& nJourneyKey);
		void runJourneyDescriptor(__i32 nJourneyId);
		void runClear();

	public:
		ArchiveService();
		~ArchiveService();

	private:
		std::map<__i32, IJourney *> mJourneys;
		std::set<std::string> mArchives;
		ArchiveReader mArchiveReader;
		std::set<__i32> mJourneyIds;
		bool mConfigure;
		bool mRelease;
	};

}
