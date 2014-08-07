#include "../DefInc.h"
#include "TimeService.h"

namespace std {

	void TimeService::setServerTime(__i64 nTime)
	{
		mCurrent = nTime;
	}

	__i64 TimeService::getServerTime()
	{
		return mCurrent;
	}

	__i64 TimeService::getNowSecond()
	{
		system_clock::time_point time_ = system_clock::now();
		duration<__i64> timePeriod = duration_cast<duration<__i64>>(time_ - mBegin);
		return timeDuration.count();
	}

	void TimeService::runPreinit()
	{
		tm begTm;
		begTm.tm_year = 2014-1900; begTm.tm_mon = 0;
		begTm.tm_mday = 1; begTm.tm_hour = 23;
		begTm.tm_min = 59; begTm.tm_sec = 59;
		time_t begTime = mktime(&begTm);
		mBegin = system_clock::from_time_t(begTime);
	}

	TimeService::TimeService()
		: mCurrent(0)
	{
	}

	TimeService::~TimeService()
	{
		mCurrent = 0;
	}

}
