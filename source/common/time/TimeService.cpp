#include "../DefInc.h"
#include "TimeService.h"

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
		luaService_.runMethod<TimeService>(&TimeService::runCommon, "runCommon");
	}

	void TimeService::runPreinit()
	{
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("TimeService run runPreinit!"));

		tm begTm; begTm.tm_year = INITYEAR-1900;
		begTm.tm_mon = INITMONTH - 1;
		begTm.tm_mday = INITDAY; begTm.tm_hour = 23;
		begTm.tm_min = 59; begTm.tm_sec = 59;
		time_t begTime = mktime(&begTm);
		mBegin = system_clock::from_time_t(begTime);
		
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&TimeService::runInit, this));
	}

	void TimeService::runInit()
	{
		TimeService::runScript();
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
#endif

