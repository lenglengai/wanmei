#pragma once

namespace std {

	class __funapi ArchiveReader : noncopyable
	{
	public:
		bool runOpen(const char * nPath);
		bool readKey(const char * nKey, char ** nBuf, __i32 * nSize);
		void freeBuf(char * nBuf, __i32 nSize);
		void runClose();

	private:
		void runClear();

	public:
		ArchiveReader();
		~ArchiveReader();

	private:
		BinReader mBinReader;
		Archive mArchive;
		char * mCommon;
	};

}
