#include "../Include.h"

namespace std {
	
	const __i32 __stringid(const char * nValue)
	{
		const CrcService& crcService_ = Singleton<CrcService>::instance();
		return crcService_.runName(nValue);
	}
	
}
