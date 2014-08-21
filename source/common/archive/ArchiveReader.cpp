#include "../DefInc.h"
#include "ArchiveReader.h"
#include "../compress/CompressService.h"

namespace std {

	void ArchiveReader::runOpen(const char * nPath)
	{
		mBinReader.openUrl(nPath);
		mArchive.headSerialize(mBinReader);
	}

	bool ArchiveReader::readKey(const char * nKey, char ** nBuf, __i32 * nSize)
	{
		memset(mCommon, 0, sizeof(mCommon));
		ArchiveHashPtr archiveHash = mArchive.getArchiveHash(nKey);
		mBinReader.runSeek(archiveHash->getBeg());
		mBinReader.runRead(mCommon, archiveHash->getEnd());
		(*nBuf) = new char[archiveHash->getSize()];
		(*nSize) = archiveHash->getSize();
		CompressService& compressService = Singleton<CompressService>::instance();
		compressService.unBZip2(mCommon, archiveHash->getEnd(), (*nBuf), nSize);
	}

	void ArchiveReader::freeBuf(char * nBuf, __i32 nSize)
	{
		delete[] nBuf;
	}

	void ArchiveReader::runClose()
	{
		memset(mCommon, 0, sizeof(mCommon));
		mBinReader.runClose();
		mArchive.runClear();
	}

	ArchiveReader::ArchiveReader()
	{
		memset(mCommon, 0, sizeof(mCommon));
	}

	ArchiveReader::~ArchiveReader()
	{
		memset(mCommon, 0, sizeof(mCommon));
	}

}
