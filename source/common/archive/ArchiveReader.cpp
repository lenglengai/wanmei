#include "../DefInc.h"
#include "BinReader.h"
#include "ArchiveReader.h"

namespace std {

	void ArchiveReader::runOpen(const char * nPath)
	{
		mBinReader.openUrl(nPath);
		mArchive.headSerialize(mBinReader);
	}

	bool ArchiveReader::readKey(const char * nKey, char ** nBuf, __i32 * nSize)
	{
		ArchiveHashPtr archiveHash = mArchive.getArchiveHash(nKey);
		memset(mCommon, 0, sizeof(mCommon));
		mBinReader._runSeek(mpqHash->_getBeg());
		mBinReader.(mCommon, mpqHash->_getEnd());
		(*nBuf) = new char[mpqHash->_getSize()];
		(*nSize) = mpqHash->_getSize();
		CompressSingleton& compressSingleton_ = __singleton<CompressSingleton>::_instance();
		compressSingleton_._unBZip2(mCommon, mpqHash->_getEnd(), (*nBuf), nSize);
	}

	void ArchiveReader::freeBuf(char * nBuf, __i32 nSize)
	{
		delete[] nBuf;
	}

	void ArchiveReader::runClose()
	{
		mBinReader.runClose();
	}

	ArchiveReader::ArchiveReader()
	{

	}

	ArchiveReader::~ArchiveReader()
	{

	}

}
