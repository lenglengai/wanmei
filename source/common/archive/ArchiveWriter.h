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
		void runOpen(const char * nUrl);
		void runArchives(std::list<std::string>& nArchives);
		void runClose();

	private:
		void runArchive(const char * nArchive);
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
