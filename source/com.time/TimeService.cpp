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
