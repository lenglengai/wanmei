#include "../Include.h"

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
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("RandomService run runScript!"));

		LuaService& luaService_ = Singleton<LuaService>::instance();
		luaService_.runClass<LogService>("RandomService");
		luaService_.runMethod<LogService>(&RandomService::runLuaRandom, "runRandom");
	}

	void RandomService::runPreinit()
	{
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("RandomService run runPreinit!"));

		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&RandomService::runInit, this));
		
		mEngine.seed(mDevice());
	}

	void RandomService::runInit()
	{
		LogService& loginService_ = Singleton<LogService>::instance();
		loginService_.logInfo(log_1("RandomService run runInit!"));

		RandomService::runScript();
	}

	RandomService::RandomService()
	{
	}

	RandomService::~RandomService()
	{
	}

}
#endif
