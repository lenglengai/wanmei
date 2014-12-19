#include "../Include.h"

namespace std {
	
	const __i32 __stringid(const char * nValue)
	{
		CrcService& crcService_ = Singleton<CrcService>::instance();
		return crcService_->runName(nValue);
	}
	
}
