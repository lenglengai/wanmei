#pragma once

namespace std {

	class __funapi TimeService : boost::noncopyable
	{
	public:
		void setServerTime(__i64 nTime);
		__i64 getServerTime();
		__i64 getNowSecond();
		
		static void runScript();
		bool runPreinit();
		void runInit();

	private:
		time_t fromTime(__i32 nYear, __i32 nMonth, __i32 nDay);
		time_t fromTime(__i32 nYear, __i32 nMonth, __i32 nDay, __i32 nHour);
		time_t fromTime(__i32 nYear, __i32 nMonth, __i32 nDay, __i32 nHour, __i32 nMin);
		time_t fromTime(__i32 nYear, __i32 nMonth, __i32 nDay, __i32 nHour, __i32 nMin, __i32 nSec);
		
	public:
		TimeService();
		~TimeService();
		
	private:
		chrono::system_clock::time_point mBegin;
		__i64 mCurrent;
	};

}
