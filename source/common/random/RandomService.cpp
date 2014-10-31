#include "../DefInc.h"
#include "RandomService.h"

#ifdef __RANDOM__
namespace std {

	void RandomService::runScript()
	{
		LuaService& luaService_ = Singleton<LuaService>::instance();
		luaService_.runClass<LogService>("RandomService");
		luaService_.runMethod<LogService>(&LogService::runLuaRandom, "runRandom");
	}

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

	void RandomService::runPreinit()
	{
		mEngine.seed(mDevice());
	}

	RandomService::RandomService()
	{
	}

	RandomService::~RandomService()
	{
	}

}
#endif
