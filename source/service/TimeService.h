#pragma once

namespace std {

	class __funapi TimeService : public IService
	{
	public:
	#ifdef __CLIENTTIME__
		void setServerTime(const __i32 nServerTime);
	#endif
		__i32 getBeforeDay(__i32 nDays) const;
		__i32 getServerTime() const;
		__i32 getLocalTime() const;
		__i32 getStartTime() const;
		
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
		bool runPreinit() OVERRIDE FINAL;
		void runLuaApi() OVERRIDE FINAL;
		void startEnd() OVERRIDE FINAL;
		
		TimeService();
		~TimeService();
		
	private:
		chrono::system_clock::time_point mBegin;
		__i32 mStartTime;
		__i32 mCurrent;
	};

}
