#pragma once

#include "Archive.h"
#include "BinReader.h"

namespace std {

	class __funapi ArchiveReader
	{
	public:
		void runOpen(const char * nPath);
		bool readKey(const char * nKey, char ** nBuf, __i32 * nSize);
		void freeBuf(char * nBuf, __i32 nSize);
		void runClose();

		ArchiveReader();
		~ArchiveReader();

	private:
		char mCommon[5 * 1024 * 1024];
		BinReader mBinReader;
		Archive mArchive;
	};

}
