#include "../../include/Include.h"

namespace std {

	void ArchiveWriter::runArchives(std::set<std::string>& nArchives)
	{
		__i32 pos_ = (ArchiveHash::hashSize()) * (nArchives.size());
		pos_ += sizeof(__i16); pos_ += ArchiveHead::hashSize();
		mBinWriter.runSeek(pos_);

		for (auto& it : nArchives) {
			this->runArchive(it.c_str());
		}
	}
	
	void ArchiveWriter::runCount(__i32 nCount)
	{
		__i32 pos_ = (ArchiveHash::hashSize()) * nCount;
		pos_ += sizeof(__i16); pos_ += ArchiveHead::hashSize();
		mBinWriter.runSeek(pos_);
	}

	void ArchiveWriter::runOpen(const char * nUrl)
	{
		mBinWriter.openUrl(nUrl);
	}

	void ArchiveWriter::runArchive(const char * nArchive)
	{
		__i32 beg_ = mBinWriter.runTell();
		__i32 size_ = this->readBuf(nArchive);
		__i32 end_ = this->writeBuf(size_);
		std::shared_ptr<ArchiveHash> archiveHash(new ArchiveHash());
		CrcService& crcService = Singleton<CrcService>::instance();
		__i32 hash_ = crcService.runCommon(nArchive);
		archiveHash->setHash(hash_);
		archiveHash->setBeg(beg_);
		archiveHash->setEnd(end_);
		archiveHash->setSize(size_);
		mArchive.pushArchiveHash(archiveHash);
	}

	__i32 ArchiveWriter::readBuf(const char * nPath)
	{
		memset(mCommon, 0, ARCHIVESIZE);
		BinReader binReader;
		binReader.openUrl(nPath);
		__i32 result_ = binReader.runLength();
		binReader.runRead(mCommon, result_);
		mCommon[result_] = 0;
		binReader.runClose();
		return result_;
	}

	__i32 ArchiveWriter::writeBuf(__i32 nSize)
	{
		__i32 result_ = ARCHIVESIZE;
		memset(mCompress, 0, ARCHIVESIZE);
		CompressService& compressService = Singleton<CompressService>::instance();
		compressService.runBZip2(mCommon, nSize, mCompress, &result_);
		mBinWriter.runWrite(mCompress, result_);
		return result_;
	}

	void ArchiveWriter::runClose()
	{
		mBinWriter.runSeek(0);
		mArchive.headSerialize(mBinWriter);
		mBinWriter.runClose();
	}

	ArchiveWriter::ArchiveWriter()
	{
		mCompress = new char[ARCHIVESIZE];
		mCommon = new char[ARCHIVESIZE];
	}

	ArchiveWriter::~ArchiveWriter()
	{
		delete[] mCompress;
		mCompress = nullptr;
		delete[] mCommon;
		mCommon = nullptr;
	}

}
