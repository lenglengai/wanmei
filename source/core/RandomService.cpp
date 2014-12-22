#include "../Include.h"

namespace std {

#ifdef __CONSOLE__
	StringWriterPtr RandomService::commandInfo(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		string className_("");
		__i32 classid_ = __classid<RandomService>(className_);
		stringWriter_.runString(className_className_, "className");
		stringWriter_.runInt32(classid_, "classId");
		return stringWriter_;
	}
	
	StringWriterPtr RandomService::commandRandom(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		const string& strMin_ = nCommand.getCommand(1);
		const string& strMax_ = nCommand.getCommand(2);
		const __i32 minValue_ = __convert<string, __i32>(strMin_);
		const __i32 maxValue_ = __convert<string, __i32>(strMax_);
		stringWriter_.runString(strMin_, "strMin");
		stringWriter_.runInt32(minValue_, "minValue");
		stringWriter_.runString(strMax_, "strMax");
		stringWriter_.runInt32(maxValue_, "maxValue");
		return stringWriter_;
	}
#endif

	__i32 RandomService::luaRandom(__i32 nMin, __i32 nMax)
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
	
	RandomService * RandomService::getRandomService()
	{
		RandomService& randomService_ = Singleton<RandomService>::instance();
		return (&randomService_);
	}

	void RandomService::runLuaApi()
	{
		LuaService& luaService_ = Singleton<LuaService>::instance();
		luaService_.runClass<RandomService>("RandomService");
		luaService_.runFun(&RandomService::getRandomService, "getRandomService");
		luaService_.runMethod<RandomService>(&RandomService::luaRandom, "runRandom");
	}

	bool RandomService::runPreinit()
	{
		mEngine.seed(mDevice());
		
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunLuaApi.connect(boost::bind(&RandomService::runLuaApi, this));
	#ifdef __CONSOLE__
		this->registerCommand("info", std::bind(&RandomService::commandInfo, this, _1));
		this->registerCommand("random", std::bind(&RandomService::commandRandom, this, _1));
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
