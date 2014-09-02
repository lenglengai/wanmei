#include "../DefInc.h"
#include "Archive.h"
#include "../crc/CrcService.h"

#ifdef __ARCHIVE__
namespace std {

	ArchiveHashPtr Archive::getArchiveHash(const char * nKey)
	{
		CrcService& crcService = Singleton<CrcService>::instance();
		__i32 hash_ = crcService.runCommon(nKey);
		std::map<__i32, ArchiveHashPtr>::iterator it = mArchiveHashs.find(hash_);
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
		mArchiveHashs.clear();
	}

	Archive::~Archive()
	{
		mArchiveHashs.clear();
	}

}
#endif
