#include "../Common.h"

#ifdef __RANDOM__
namespace std {

	__i32 RandomService::runLuaRandom(__i32 nMin, __i32 nMax)
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
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("RandomService run runScript!"));
	#endif
		LuaService& luaService_ = Singleton<LuaService>::instance();
		luaService_.runClass<LogService>("RandomService");
		luaService_.runMethod<LogService>(&RandomService::runLuaRandom, "runRandom");
	#ifdef __LOG__
		logService_.logInfo(log_1("RandomService run runScript finish!"));
	#endif
	}

	bool RandomService::runPreinit()
	{
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("RandomService run runPreinit!"));
	#endif
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&RandomService::runInit, this));
		
		mEngine.seed(mDevice());
	#ifdef __LOG__
		logService_.logInfo(log_1("RandomService run runPreinit finish!"));
	#endif
		return true;
	}

	bool RandomService::runInit()
	{
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("RandomService run runInit!"));
	#endif
		RandomService::runScript();
	#ifdef __LOG__
		logService_.logInfo(log_1("RandomService run runInit finish!"));
	#endif
		return true;
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
