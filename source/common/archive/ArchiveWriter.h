#pragma once

#include "Archive.h"
#include "BinWriter.h"

namespace std {

	class __funapi ArchiveWriter
	{
	public:

		ArchiveWriter();
		~ArchiveWriter();

	private:
		char mCompress[5 * 1024 * 1024];
		char mCommon[5 * 1024 * 1024];
		BinWriter mBinWriter;
		Archive mArchive;
	};

}
