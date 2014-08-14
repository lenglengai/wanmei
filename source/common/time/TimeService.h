#pragma once

#include <chrono>

using namespace std::chrono;

namespace std {

	class __funapi TimeService : boost::noncopyable
	{
	public:
		void setServerTime(__i64 nTime);
		__i64 getServerTime();
		__i64 getNowSecond();
		void runPreinit();
		TimeService();
		~TimeService();
	private:
		system_clock::time_point mBegin;
		__i64 mCurrent;
	};

}
