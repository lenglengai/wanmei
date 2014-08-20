#pragma once

#include "Archive.h"

namespace std {

	class ArchiveReader
	{
	public:
		void runOpen(const char * nPath);
		bool readKey(const char * nKey, char ** nBuf, __i32 * nSize);
		void freeBuf(char * nBuf, __i32 nSize);
		void runClose();

		ArchiveReader();
		~ArchiveReader();

	private:
		BinReader mBinReader;
		Archive mArchive;
	};

}
