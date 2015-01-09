#include "../Include.h"

namespace std {

#ifdef __CONSOLE__
	const StringWriterPtr TimeService::commandInfo(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		string className_(""); __i32 serverTime_ = 0;
		__i32 classid_ = __classinfo<TimeService>(className_);
		stringWriter_->runString(className_, "className");
		stringWriter_->runInt32(classid_, "classId");
		serverTime_ = this->getServerTime();
		stringWriter_->runInt32(serverTime_, "serverTime");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
#endif

#ifdef __CLIENT__
	void TimeService::setServerTime(const __i32 nServerTime)
	{
		mCurrent = nServerTime - this->getLocalTime();
	}
#endif

	__i32 TimeService::getServerTime() const
	{
	#ifdef __CLIENT__
		return (this->getLocalTime() + mCurrent);
	#endif
	#ifdef __SERVER__
		return this->getLocalTime();
	#endif
	}
	
	__i32 TimeService::getBeforeDay(__i32 nDays) const
	{
		__i32 nowTime_ = this->getLocalTime();
		return (nowTime_ - (nDays * 86400));
	}
	
	__i32 TimeService::getLocalTime() const
	{
		chrono::system_clock::time_point timePoint_ = chrono::system_clock::now();
		chrono::seconds timePeriod_ = chrono::duration_cast<chrono::seconds>(timePoint_ - mBegin);
		return static_cast<__i32>(timePeriod_.count());
	}
	
	TimeService * TimeService::getTimeService()
	{
		TimeService& timeService_ = Singleton<TimeService>::instance();
		return (&timeService_);
	}
	
	void TimeService::runLuaApi()
	{
	#ifdef __EXPLUA__
		LuaService& luaService_ = Singleton<LuaService>::instance();
		luaService_.runClass<TimeService>("TimeService");
		luaService_.runFun(&TimeService::getTimeService, "getTimeService");
		luaService_.runMethod<TimeService>(&TimeService::getServerTime, "getServerTime");
		luaService_.runMethod<TimeService>(&TimeService::getLocalTime, "getLocalTime");
	#endif
	}
	
	void TimeService::startEnd()
	{
		mStartTime = this->getLocalTime();
	}
	
	__i32 TimeService::getStartTime() const
	{
		if (0 == mStartTime) return 0;
		return (this->getLocalTime() - mStartTime);
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
	#ifdef __CONSOLE__
		this->registerCommand("info", std::bind(&TimeService::commandInfo, this, placeholders::_1));
	#endif
		return true;
	}
	
	const time_t TimeService::fromTime(const __i32 nYear, const __i32 nMonth, const __i32 nDay) const
	{
		return fromTime(nYear, nMonth, nDay, 0, 0, 0);
	}
	
	const time_t TimeService::fromTime(const __i32 nYear, const __i32 nMonth, const __i32 nDay, const __i32 nHour) const
	{
		return fromTime(nYear, nMonth, nDay, nHour, 0, 0);
	}
	
	const time_t TimeService::fromTime(const __i32 nYear, const __i32 nMonth, const __i32 nDay, const __i32 nHour, const __i32 nMin) const
	{
		return fromTime(nYear, nMonth, nDay, nHour, nMin, 0);
	}
	
	const time_t TimeService::fromTime(const __i32 nYear, const __i32 nMonth, const __i32 nDay, const __i32 nHour, const __i32 nMin, const __i32 nSec) const
	{
		tm tm_; tm_.tm_year = nYear-1900;
		tm_.tm_mon = nMonth - 1;
		tm_.tm_mday = nDay; tm_.tm_hour = nHour;
		tm_.tm_min = nMin; tm_.tm_sec = nSec;
		return mktime(&tm_);
	}

	TimeService::TimeService()
		: mStartTime(0)
		, mCurrent(0)
	{
	}

	TimeService::~TimeService()
	{
		mStartTime = 0;
		mCurrent = 0;
	}
	
	static Service<TimeService> sTimeService;

}
