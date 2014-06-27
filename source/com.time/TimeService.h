#pragma once

#include <boost/date_time.hpp>

namespace std {

	class TimeService : boost::noncopyable
	{
	public:
		void setServerTime(__i64 nTime);
		__i64 getServerTime();
		void runPreinit();
		TimeService();
		~TimeService();
	private:
		boost::posix_time::ptime mBegin;
		__i64 mCurrent;
	};

}
