#include "../Common.h"

#ifdef __WITHTIME__
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
		return timePeriod.count();
	}

	void TimeService::runScript()
	{
		LuaService& luaService_ = Singleton<LuaService>::instance();
		luaService_.runClass<TimeService>("TimeService");
		luaService_.runMethod<TimeService>(&TimeService::getServerTime, "getServerTime");
		luaService_.runMethod<TimeService>(&TimeService::getNowSecond, "getNowSecond");
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	#endif
	}

	bool TimeService::runPreinit()
	{
		system_clock::time_point nowPoint = system_clock::now();
		
		time_t startTime = this->fromTime(STARTYEAR, STARTMONTH, STARTDAY);
		system_clock::time_point startPoint = system_clock::from_time_t(startTime);
		if (startPoint > nowPoint) {
		#ifdef __LOG__
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1("startPoint > nowPoint!"));
		#endif
			return false;
		}
		
		time_t endTime = this->fromTime(ENDYEAR, ENDMONTH, ENDDAY);
		system_clock::time_point endPoint = system_clock::from_time_t(endTime);
		if (nowPoint > endPoint) {
		#ifdef __LOG__
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1("nowPoint > endPoint!"));
		#endif
			return false;
		}
		
		time_t begTime = this->fromTime(INITYEAR, INITMONTH, INITDAY);
		mBegin = system_clock::from_time_t(begTime);
		
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&TimeService::runInit, this));
		#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
		#endif
		return true;
	}
	
	time_t TimeService::fromTime(__i32 nYear, __i32 nMonth, __i32 nDay)
	{
		return fromTime(nYear, nMonth, nDay, 0, 0, 0);
	}
	
	time_t TimeService::fromTime(__i32 nYear, __i32 nMonth, __i32 nDay, __i32 nHour)
	{
		return fromTime(nYear, nMonth, nDay, nHour, 0, 0);
	}
	
	time_t TimeService::fromTime(__i32 nYear, __i32 nMonth, __i32 nDay, __i32 nHour, __i32 nMin)
	{
		return fromTime(nYear, nMonth, nDay, nHour, nMin, 0);
	}
	
	time_t TimeService::fromTime(__i32 nYear, __i32 nMonth, __i32 nDay, __i32 nHour, __i32 nMin, __i32 nSec)
	{
		tm tm_; tm_.tm_year = nYear-1900;
		tm_.tm_mon = nMonth - 1;
		tm_.tm_mday = nDay; tm_.tm_hour = nHour;
		tm_.tm_min = nMin; tm_.tm_sec = nSec;
		return mktime(&tm_);
	}

	void TimeService::runInit()
	{
		TimeService::runScript();
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	#endif
	}

	TimeService::TimeService()
		: mCurrent(0)
	{
	}

	TimeService::~TimeService()
	{
		mCurrent = 0;
	}
	
	static Preinit<TimeService> sTimeServicePreinit;

}
#endif
