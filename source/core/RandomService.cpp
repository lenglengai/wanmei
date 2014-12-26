#include "../Include.h"

namespace std {

#ifdef __CONSOLE__
	const StringWriterPtr RandomService::commandInfo(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		string className_("");
		__i32 classid_ = __classinfo<RandomService>(className_);
		stringWriter_->runString(className_, "className");
		stringWriter_->runInt32(classid_, "classId");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
	
	const StringWriterPtr RandomService::commandRandom(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		const string& strMin_ = nCommandArgs.getCommandArg(1);
		const string& strMax_ = nCommandArgs.getCommandArg(2);
		const __i32 minValue_ = __convert<string, __i32>(strMin_);
		const __i32 maxValue_ = __convert<string, __i32>(strMax_);
		stringWriter_->runString(strMin_, "strMin");
		stringWriter_->runInt32(minValue_, "minValue");
		stringWriter_->runString(strMax_, "strMax");
		stringWriter_->runInt32(maxValue_, "maxValue");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
#endif

	__i32 RandomService::luaRandom(const __i32 nMin, const __i32 nMax)
	{
		return this->runRandom(nMin, nMax);
	}

	__i32 RandomService::runRandom(const __i32 nMin, const __i32 nMax)
	{
		uniform_int_distribution<> distribution_(nMin, nMax);
		return distribution_(mEngine);
	}

	__i32 RandomService::runRandom(const __i32 nMax)
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
		this->registerCommand("info", std::bind(&RandomService::commandInfo, this, placeholders::_1));
		this->registerCommand("random", std::bind(&RandomService::commandRandom, this, placeholders::_1));
	#endif
		return true;
	}

	RandomService::RandomService()
	{
	}

	RandomService::~RandomService()
	{
	}
	
	static Preinit0<RandomService> sRandomServicePreinit;

}
