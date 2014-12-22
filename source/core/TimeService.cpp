#include "../Include.h"

namespace std {

#ifdef __CONSOLE__
	StringWriterPtr TimeService::commandInfo(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		string className_(""); __i64 serverTime_ = 0;
		__i32 classid_ = __classid<TimeService>(className_);
		stringWriter_.runString(className_className_, "className");
		stringWriter_.runInt32(classid_, "classId");
		serverTime_ = this->getServerTime();
		stringWriter_.runInt64(serverTime_, "serverTime");
		return stringWriter_;
	}
#endif

#ifdef __CLIENT__
	void TimeService::setServerTime(__i64 nServerTime)
	{
		mCurrent = nServerTime - this->getLocalTime();
	}
#endif

	__i64 TimeService::getServerTime()
	{
	#ifdef __CLIENT__
		return (this->getLocalTime() + mCurrent);
	#endif
	#ifdef __SERVER__
		return this->getLocalTime();
	#endif
	}
	
	__i64 TimeService::getLocalTime()
	{
		chrono::system_clock::time_point time_ = chrono::system_clock::now();
		chrono::duration<__i64> timePeriod = chrono::duration_cast<chrono::duration<__i64>>(time_ - mBegin);
		return timePeriod.count();
	}
	
	TimeService * TimeService::getTimeService()
	{
		TimeService& timeService_ = Singleton<TimeService>::instance();
		return (&timeService_);
	}
	
	void TimeService::runLuaApi()
	{
		LuaService& luaService_ = Singleton<LuaService>::instance();
		luaService_.runClass<TimeService>("TimeService");
		luaService_.runFun(&TimeService::getTimeService, "getTimeService");
		luaService_.runMethod<TimeService>(&TimeService::getServerTime, "getServerTime");
		luaService_.runMethod<TimeService>(&TimeService::getLocalTime, "getLocalTime");
	}

	bool TimeService::runPreinit()
	{
		chrono::system_clock::time_point nowPoint = chrono::system_clock::now();
		
		time_t startTime = this->fromTime(STARTYEAR, STARTMONTH, STARTDAY);
		chrono::system_clock::time_point startPoint = chrono::system_clock::from_time_t(startTime);
		if (startPoint > nowPoint) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1("startPoint > nowPoint!"));
			return false;
		}
		
		time_t endTime = this->fromTime(ENDYEAR, ENDMONTH, ENDDAY);
		chrono::system_clock::time_point endPoint = chrono::system_clock::from_time_t(endTime);
		if (nowPoint > endPoint) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1("nowPoint > endPoint!"));
			return false;
		}
		
		time_t begTime = this->fromTime(INITYEAR, INITMONTH, INITDAY);
		mBegin = chrono::system_clock::from_time_t(begTime);
		
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunLuaApi.connect(boost::bind(&TimeService::runLuaApi, this));
	#ifdef __CONSOLE__
		this->registerCommand("info", std::bind(&TimeService::commandInfo, this, _1));
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
