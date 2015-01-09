#include "../Include.h"

namespace std {

	bool ArchiveReader::runOpen(const char * nPath)
	{
		if (!mBinReader.openUrl(nPath)) return false;
		mArchive.headSerialize(mBinReader);
		return true;
	}

	bool ArchiveReader::readKey(const char * nKey, char ** nBuf, __i32 * nSize)
	{
		this->runClear();
		ArchiveHashPtr archiveHash = mArchive.getArchiveHash(nKey);
		mBinReader.runSeek(archiveHash->getBeg());
		mBinReader.runRead(mCommon, archiveHash->getEnd());
		(*nBuf) = new char[archiveHash->getSize()];
		(*nSize) = archiveHash->getSize();
		CompressService& compressService = Service<CompressService>::instance();
		compressService.unBZip2(mCommon, archiveHash->getEnd(), (*nBuf), nSize);
		return true;
	}

	void ArchiveReader::freeBuf(char * nBuf, const __i32 nSize)
	{
		delete[] nBuf;
	}

	void ArchiveReader::runClear()
	{
		memset(mCommon, 0, ARCHIVESIZE);
	}

	void ArchiveReader::runClose()
	{
		this->runClear();
		mBinReader.runClose();
		mArchive.runClear();
	}

	ArchiveReader::ArchiveReader()
	{
		mCommon = new char[ARCHIVESIZE];
		this->runClear();
	}

	ArchiveReader::~ArchiveReader()
	{
		this->runClear();
		delete[] mCommon;
		mCommon = nullptr;
	}

}
