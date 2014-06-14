#include "../DefInc.h"

#include "CrcService.h"
#include "crypt_buf.h"

namespace std {

	__i64 CrcService::runId(const char * nName)
	{
		boost::posix_time::ptime time_(boost::posix_time::second_clock::local_time());
		boost::posix_time::time_period timePeriod(mTime, time_);
		boost::posix_time::time_duration timeDuration = timePeriod.length();
		__i64 seconds_ = timeDuration.total_seconds();
		seconds_ /= 10;
		__i64 result_ = this->runCommon(nName);
		result_ <<= 32;
		result_ += seconds_;
		return result_;
	}

	__i64 CrcService::runId(__i32 nId)
	{
		boost::posix_time::ptime time_(boost::posix_time::second_clock::local_time());
		boost::posix_time::time_period timePeriod(mTime, time_);
		boost::posix_time::time_duration timeDuration = timePeriod.length();
		__i64 seconds_ = timeDuration.total_seconds();
		seconds_ /= 10;
		__i64 result_ = nId;
		result_ <<= 32;
		result_ += seconds_;
		return result_;
	}

	__i32 CrcService::runCommon(const char * nName)
	{
		return this->hashString(nName, 0x100);
	}

	__i32 CrcService::runComputer()
	{
		//1282682146
		return this->hashString("computer", 0x100);
	}

	__i32 CrcService::runCellphone()
	{
		//318023319
		return this->hashString("cellphone", 0x150);
	}

	__i32 CrcService::runName(const char * nName)
	{
		return this->hashString(nName, 0x50);
	}
	
	__i32 CrcService::runPassward(const char * nName)
	{
		return this->hashString(nName, 0x300);
	}

	__i32 CrcService::runCluster(const char * nName)
	{
		return this->hashString(nName, 0x100);
	}

	__i32 CrcService::runServer(const char * nName)
	{
		return this->hashString(nName, 0x150);
	}

	__i32 CrcService::runDatabase(const char * nName)
	{
		return this->hashString(nName, 0x200);
	}

	__i32 CrcService::runTable(const char * nName)
	{
		return this->hashString(nName, 0x250);
	}

	__i32 CrcService::hashString(const char * nKey, __i16 nOffset)
	{
		__i32 seed1 = 0x7FED7FED;
		__i32 seed2 = 0xEEEEEEEE;

		__i32 ch;

		while (*nKey != 0) {
			ch = toupper(*nKey++, locale());
			seed1 = crypt_buf[nOffset + ch] ^ (seed1 + seed2);
			seed2 = ch + seed1 + seed2 + (seed2 << 5) + 3;
		}

		return seed1;
	}

	void CrcService::runPreinit()
	{
		mTime = boost::posix_time::time_from_string(string(INITTIME));
	}

	CrcService::CrcService()
	{
	}

	CrcService::~CrcService()
	{
	}

}
