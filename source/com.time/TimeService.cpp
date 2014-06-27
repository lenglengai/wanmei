#include "../com.common/DefInc.h"
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
		boost::posix_time::ptime time_(boost::posix_time::second_clock::local_time());
		boost::posix_time::time_period timePeriod(mBegin, time_);
		boost::posix_time::time_duration timeDuration = timePeriod.length();
		return timeDuration.total_seconds();
	}

	void TimeService::runPreinit()
	{
		mBegin = boost::posix_time::time_from_string(string(INITTIME));
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
