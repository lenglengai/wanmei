#pragma once

#include "JourneyDescripter.h"
#include "BinWriter.h"
#include "Archive.h"

namespace std {

	class __funapi ArchiveWriter
	{
	public:
		void runJourneyDescripter(JourneyDescripter& nJourneyDescripter);
		void runClose();

	private:
		void runJourney(std::string& nJourney);
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
