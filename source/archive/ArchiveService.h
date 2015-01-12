#pragma once

#include "Archive.h"
#include "XmlReader.h"
#include "ArchiveWriter.h"
#include "ArchiveReader.h"

namespace std {

	class __funapi ArchiveService : public IService
	{
	public:
		template<class __t>
		bool loadBuf(__t * nT, char ** nBuf, __i32 * nSize)
		{
			const char * streamUrl_ = nT->streamUrl();
			if ( !mArchiveReader.readKey(streamUrl_, nBuf, nSize) ) {
				LogService& logService_ = Service<LogService>::instance();
				logService_.logError(log_1(streamUrl_));
				return false;
			}
			return true;
		}
		
		void freeBuf(char * nBuf, const __i32 nSize);
		
		template<class __t>
		bool archiveStream(__t * nT, char * nBuf)
		{
			const char * streamName_ = nT->streamName();
			XmlReader xmlReader_;
			xmlReader_.openStr(nBuf);
			xmlReader_.selectStream(streamName_);
			nT->headSerialize(xmlReader_);
			xmlReader_.runClose();
			return true;
		}
		
		template<class __t>
		bool xmlStream(__t * nT)
		{
			const char * streamUrl_ = nT->streamUrl();
			const char * streamName_ = nT->streamName();
			XmlReader xmlReader_;
			if (xmlReader_.openUrl(streamUrl_)) {
				xmlReader_.selectStream(streamName_);
				nT->headSerialize(xmlReader_);
				xmlReader_.runClose();
				return true;
			}
			return false;
		}
		
		template<class __t>
		bool loadStream(__t * nT)
		{
		#ifdef __CONSOLE__
			if (mIsWriter) {
				const char * streamUrl_ = nT->streamUrl();
				this->registerArchive(streamUrl_);
				return true;
			}
		#endif
			if (!mIsArchive) {
				return this->xmlStream(nT);
			}
			char * nBuf = nullptr; __i32 nSize = 0;
			if (!this->loadBuf(nT, &nBuf, &nSize)) {
				return false;
			}
			this->archiveStream(nT, nBuf);
			this->freeBuf(nBuf, nSize);
			return true;
		}
		
	private:
	#ifdef __CONSOLE__
		const StringWriterPtr commandInfo(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandReload(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandConfigure(const CommandArgs& nCommandArgs);
		void registerArchive(const char * nArchive);
	#endif
	
	public:
		bool runPreinit() OVERRIDE FINAL;
		void runClear() OVERRIDE FINAL;

	public:
		ArchiveService();
		~ArchiveService();

	private:
		ArchiveReader mArchiveReader;
		bool mIsArchive;
	#ifdef __CONSOLE__
		ArchiveWriter mArchiveWriter;
		set<string> mArchives;
		bool mIsWriter;
	#endif
	};

}
