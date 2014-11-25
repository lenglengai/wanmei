#pragma once

namespace std {

	class __funapi ArchiveWriter : boost::noncopyable
	{
	public:
		void runOpen(const char * nUrl);
		void runArchives(std::set<std::string>& nArchives);
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
