#include "../DefInc.h"
#include "../crc/CrcService.h"
#include "Archive.h"

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

	Archive::Archive()
	{
		mArchiveHashs.clear();
	}

	Archive::~Archive()
	{
		mArchiveHashs.clear();
	}

}
