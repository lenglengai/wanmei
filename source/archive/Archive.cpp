#include "../Include.h"

namespace std {

	ArchiveHashPtr Archive::getArchiveHash(const char * nKey)
	{
		CrcService& crcService = Singleton<CrcService>::instance();
		__i32 hash_ = crcService.runCommon(nKey);
		auto it = mArchiveHashs.find(hash_);
		if (it == mArchiveHashs.end()) {
			return ArchiveHashPtr(new ArchiveHash());
		}
		return it->second;
	}

	void Archive::pushArchiveHash(ArchiveHashPtr& nArchiveHash)
	{
		mArchiveHashs[nArchiveHash->getKey()] = nArchiveHash;
	}

	void Archive::runClear()
	{
		mArchiveHead.runClear();
		mArchiveHashs.clear();
	}

	Archive::Archive()
	{
		this->runClear();
	}

	Archive::~Archive()
	{
		this->runClear();
	}

}
