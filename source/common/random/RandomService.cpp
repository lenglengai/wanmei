#include "../Common.h"

#ifdef __RANDOM__
namespace std {

	__i32 RandomService::luaRunRandom(__i32 nMin, __i32 nMax)
	{
		return this->runRandom(nMin, nMax);
	}

	__i32 RandomService::runRandom(__i32 nMin, __i32 nMax)
	{
		std::uniform_int_distribution<> distribution_(nMin, nMax);
		return distribution_(mEngine);
	}

	__i32 RandomService::runRandom(__i32 nMax)
	{
		return this->runRandom(0, nMax);
	}

	__i32 RandomService::runRandom()
	{
		return this->runRandom(65535);
	}

	void RandomService::runScript()
	{
		LuaService& luaService_ = Singleton<LuaService>::instance();
		luaService_.runClass<LogService>("RandomService");
		luaService_.runMethod<LogService>(&RandomService::luaRunRandom, "runRandom");
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	#endif
	}

	bool RandomService::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&RandomService::runInit, this));
		
		mEngine.seed(mDevice());
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	#endif
		return true;
	}

	void RandomService::runInit()
	{
		RandomService::runScript();
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	#endif
	}

	RandomService::RandomService()
	{
	}

	RandomService::~RandomService()
	{
	}
	
	static Preinit<RandomService> sRandomServicePreinit;

}
#endif
