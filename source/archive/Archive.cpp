#include "../Include.h"

namespace std {

	const ArchiveHashPtr& Archive::getArchiveHash(const char * nKey) const
	{
		CrcService& crcService = Singleton<CrcService>::instance();
		__i32 hash_ = crcService.runCommon(nKey);
		auto it = mArchiveHashs.find(hash_);
		if (it == mArchiveHashs.end()) {
			return __defaultptr<ArchiveHash>();
		}
		return it->second;
	}

	void Archive::pushArchiveHash(const ArchiveHashPtr& nArchiveHash)
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
