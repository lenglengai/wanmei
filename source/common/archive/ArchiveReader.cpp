#include "../DefInc.h"
#include "ArchiveReader.h"
#include "../setting/SettingService.h"
#include "../compress/CompressService.h"

namespace std {

	void ArchiveReader::runOpen(const char * nPath)
	{
		mBinReader.openUrl(nPath);
		mArchive.headSerialize(mBinReader);
	}

	bool ArchiveReader::readKey(const char * nKey, char ** nBuf, __i32 * nSize)
	{
		this->runClear();
		ArchiveHashPtr archiveHash = mArchive.getArchiveHash(nKey);
		mBinReader.runSeek(archiveHash->getBeg());
		mBinReader.runRead(mCommon, archiveHash->getEnd());
		(*nBuf) = new char[archiveHash->getSize()];
		(*nSize) = archiveHash->getSize();
		CompressService& compressService = Singleton<CompressService>::instance();
		compressService.unBZip2(mCommon, archiveHash->getEnd(), (*nBuf), nSize);
		return true;
	}

	void ArchiveReader::freeBuf(char * nBuf, __i32 nSize)
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
		delete[] mCommon;
		mCommon = nullptr;
	}

}
