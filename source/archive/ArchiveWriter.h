#pragma once

namespace std {

	class __funapi ArchiveWriter : noncopyable
	{
	public:
		void runOpen(const char * nUrl);
		void runArchives(const set<string>& nArchives);
		void runArchive(const char * nArchive);
		void runCount(const __i32 nCount);
		void runClear();
		void runClose();

	private:
		__i32 readBuf(const char * nPath);
		__i32 writeBuf(const __i32 nSize);

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
