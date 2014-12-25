#pragma once

namespace std {

	class __funapi TimeService : public IService
	{
	public:
	#ifdef __CLIENT__
		void setServerTime(const __i64 nServerTime);
	#endif
		__i64 getServerTime() const;
		__i64 getLocalTime() const;
		
		static TimeService * getTimeService();
		
	private:
		const time_t fromTime(const __i32 nYear, const __i32 nMonth, const __i32 nDay) const;
		const time_t fromTime(const __i32 nYear, const __i32 nMonth, const __i32 nDay, const __i32 nHour) const;
		const time_t fromTime(const __i32 nYear, const __i32 nMonth, const __i32 nDay, const __i32 nHour, const __i32 nMin) const;
		const time_t fromTime(const __i32 nYear, const __i32 nMonth, const __i32 nDay, const __i32 nHour, const __i32 nMin, const __i32 nSec) const;
		
	#ifdef __CONSOLE__
		const StringWriterPtr commandInfo(const CommandArgs& nCommandArgs);
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
