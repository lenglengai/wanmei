#pragma once

namespace std {

	class __funapi TimeService : public IService
	{
	public:
	#ifdef __CLIENT__
		void setServerTime(__i64 nServerTime);
	#endif
		__i64 getServerTime();
		__i64 getLocalTime();
		
		static TimeService * getTimeService();
		
	private:
		time_t fromTime(__i32 nYear, __i32 nMonth, __i32 nDay);
		time_t fromTime(__i32 nYear, __i32 nMonth, __i32 nDay, __i32 nHour);
		time_t fromTime(__i32 nYear, __i32 nMonth, __i32 nDay, __i32 nHour, __i32 nMin);
		time_t fromTime(__i32 nYear, __i32 nMonth, __i32 nDay, __i32 nHour, __i32 nMin, __i32 nSec);
		
	#ifdef __CONSOLE__
		StringWriterPtr commandInfo(const CommandArgs& nCommand);
	#endif
	
	public:
		bool runPreinit();
		void runLuaApi();
		
		TimeService();
		~TimeService();
		
	private:
		chrono::system_clock::time_point mBegin;
		__i64 mCurrent;
	};

}
