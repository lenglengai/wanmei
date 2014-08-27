#include "../DefInc.h"
#include "ArchiveWriter.h"
#include "../crc/CrcService.h"
#include "../setting/SettingService.h"
#include "../compress/CompressService.h"

namespace std {

	void ArchiveWriter::runJourneyDescripter(JourneyDescripter& nJourneyDescripter)
	{
		std::list<std::string>& journeys = nJourneyDescripter.getJourneys();
		__i32 pos_ = ( ArchiveHash::hashSize() ) * ( journeys.size() );
		pos_ += sizeof(__i16); pos_ += ArchiveHead::hashSize();
		std::string journey = "journey_"; 
		__i32 journeyIndex = nJourneyDescripter.getJourney();
		journey += __convert<std::string, __i32>(journeyIndex);
		journey += ".wf";
		mBinWriter.openUrl(journey.c_str());
		mBinWriter.runSeek(pos_);
		for (auto it : journeys) {
			this->runJourney(it);
		}
	}

	void ArchiveWriter::runJourney(std::string& nJourney)
	{
		__i32 beg_ = mBinWriter.runTell();
		__i32 size_ = this->readBuf(nJourney.c_str());
		__i32 end_ = this->writeBuf(size_);
		std::shared_ptr<ArchiveHash> archiveHash(new ArchiveHash());
		CrcService& crcService = Singleton<CrcService>::instance();
		archiveHash->setHash(crcService.runCommon(nJourney.c_str()));
		archiveHash->setBeg(beg_);
		archiveHash->setEnd(end_);
		archiveHash->setSize(size_);
		mArchive.pushArchiveHash(archiveHash);
	}

	__i32 ArchiveWriter::readBuf(const char * nPath)
	{
		SettingService& settingService_ = Singleton<SettingService>::instance();
		std::string url_ = settingService_.systemPath();
		if ("" != url_) url_ += "/"; url_ += nPath;
		__i32 result_ = 0;
		fstream fstream_;
		fstream_.open(url_, ios::binary | ios::in);
		fstream_.seekg(0, ios::end);
		result_ = static_cast<__i32>(fstream_.tellg());
		fstream_.seekg(0, ios::beg);
		memset(mCommon, 0, ARCHIVESIZE);
		fstream_.read(mCommon, result_);
		mCommon[result_] = 0;
		fstream_.close();
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
