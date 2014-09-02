#include "../DefInc.h"
#include "RandomService.h"
#include "../log/LogService.h"

#include <cstdlib>
#include <ctime>

#ifdef __RANDOM__
namespace std {

	__i32 RandomService::runRandom(__i32 nMin, __i32 nMax)
	{
		if (nMin > nMax) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_2(nMin, nMax));
			__i32 max_ = nMin - nMax;
			__i32 result_ = this->runRandom(max_);
			return (result_ + nMax);
		} else if (nMin == nMax) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_2(nMin, nMax));
			return nMin;
		} else {
			__i32 max_ = nMax - nMin;
			__i32 result_ = this->runRandom(max_);
			return (result_ + nMin);
		}
	}

	__i32 RandomService::runRandom(__i32 nMax)
	{
		return (this->runRandom() % nMax);
	}

	__i32 RandomService::runRandom()
	{
		return rand();
	}

	void RandomService::runPreinit()
	{
		srand(time(nullptr));
	}

	RandomService::RandomService()
	{
	}

	RandomService::~RandomService()
	{
	}

}
#endif
