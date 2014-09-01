#include "../DefInc.h"
#include "ArchiveWriter.h"
#include "../crc/CrcService.h"
#include "../setting/SettingService.h"
#include "../compress/CompressService.h"

#ifdef __ARCHIVE__
namespace std {

	void ArchiveWriter::runJourneyDescripter(JourneyDescripter& nJourneyDescripter)
	{
		__i32 journeyIndex = nJourneyDescripter.getJourney();
		std::string journey = "journey_";
		journey += __convert<std::string, __i32>(journeyIndex);
		journey += ".jf";
		mBinWriter.openUrl(journey.c_str());
		
		std::list<std::string>& journeys = nJourneyDescripter.getJourneys();
		__i32 pos_ = ( ArchiveHash::hashSize() ) * ( journeys.size() );
		pos_ += sizeof(__i16); pos_ += ArchiveHead::hashSize();	
		mBinWriter.runSeek(pos_);
		
		for (auto it : journeys) {
			this->runArchive(it);
		}
	}

	void ArchiveWriter::runConfigureDescripter(ConfigureDescripter& nConfigureDescripter)
	{
		std::string configure = "configure.jf";
		mBinWriter.openUrl(configure.c_str());

		std::list<std::string>& configures = nConfigureDescripter.getConfigures();
		__i32 pos_ = (ArchiveHash::hashSize()) * (configures.size());
		pos_ += sizeof(__i16); pos_ += ArchiveHead::hashSize();
		mBinWriter.runSeek(pos_);

		for (auto it : configures) {
			this->runArchive(it);
		}
	}

	void ArchiveWriter::runArchive(std::string& nArchive)
	{
		__i32 beg_ = mBinWriter.runTell();
		__i32 size_ = this->readBuf(nArchive.c_str());
		__i32 end_ = this->writeBuf(size_);
		std::shared_ptr<ArchiveHash> archiveHash(new ArchiveHash());
		CrcService& crcService = Singleton<CrcService>::instance();
		archiveHash->setHash(crcService.runCommon(nArchive.c_str()));
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
#endif
