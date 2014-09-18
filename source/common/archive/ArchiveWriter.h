#pragma once

#include "JourneyDescripter.h"
#include "ConfigureDescripter.h"
#include "BinWriter.h"
#include "BinReader.h"
#include "Archive.h"

#ifdef __ARCHIVE__
namespace std {

	class __funapi ArchiveWriter
	{
	public:
		void runJourneyDescripter(JourneyDescripter& nJourneyDescripter);
		void runConfigureDescripter(ConfigureDescripter& nConfigureDescripter);
		void runOpen(const char * nUrl);
		void runArchive(const char * nArchive);
		void runClose();

	private:
		__i32 readBuf(const char * nPath);
		__i32 writeBuf(__i32 nSize);

	public:
		ArchiveWriter();
		~ArchiveWriter();

	private:
		BinWriter mBinWriter;
		Archive mArchive;
		char * mCompress;
		char * mCommon;
	};

}
#endif
