#include "../Include.h"

#include "crypt_buf.h"

namespace std {

#ifdef __CONSOLE__
	StringWriterPtr CrcService::commandInfo(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		string className_("");
		__i32 classid_ = __classid<CrcService>(className_);
		stringWriter_.runString(className_className_, "className");
		stringWriter_.runInt32(classid_, "classId");
		return stringWriter_;
	}
	
	StringWriterPtr CrcService::commandNameId(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		const string& strValue_ = nCommand.getCommand(1);
		const __i64 valueId_ = this->runId(value_.c_str());
		stringWriter_.runString(strValue_, "strValue");
		stringWriter_.runInt64(valueId_, "valueId");
		return stringWriter_;
	}
	
	StringWriterPtr CrcService::commandIntId(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		const string& strValue_ = nCommand.getCommand(1);
		const __i32 value_ = __convert<string, __i32>(strValue_);
		const __i64 valueId_ = this->runId(value_);
		stringWriter_.runString(strValue_, "strValue");
		stringWriter_.runInt64(valueId_, "valueId");
		return stringWriter_;
	}
	
	StringWriterPtr CrcService::commandCommon(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		const string& strValue_ = nCommand.getCommand(1);
		const __i32 valueId_ = this->runCommon(strValue_.c_str());
		stringWriter_.runString(strValue_, "strValue");
		stringWriter_.runInt32(valueId_, "valueId");
		return stringWriter_;
	}
	
	StringWriterPtr CrcService::commandComputer(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		const __i32 computerId_ = this->runComputer();
		stringWriter_.runInt32(computerId_, "computerId");
		return stringWriter_;
	}
	
	StringWriterPtr CrcService::commandCellphone(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		const __i32 cellphoneId_ = this->runCellphone();
		stringWriter_.runInt32(cellphoneId_, "cellphoneId");
		return stringWriter_;
	}
	
	StringWriterPtr CrcService::commandName(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		const string& strValue_ = nCommand.getCommand(1);
		const __i32 valueId_ = this->runName(strValue_.c_str());
		stringWriter_.runString(strValue_, "strValue");
		stringWriter_.runInt32(valueId_, "valueId");
		return stringWriter_;
	}
	
	StringWriterPtr CrcService::commandPassward(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		const string& strValue_ = nCommand.getCommand(1);
		const __i32 valueId_ = this->runPassward(strValue_.c_str());
		stringWriter_.runString(strValue_, "strValue");
		stringWriter_.runInt32(valueId_, "valueId");
		return stringWriter_;
	}
	
	StringWriterPtr CrcService::commandCluster(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		const string& strValue_ = nCommand.getCommand(1);
		const __i32 valueId_ = this->runCluster(strValue_.c_str());
		stringWriter_.runString(strValue_, "strValue");
		stringWriter_.runInt32(valueId_, "valueId");
		return stringWriter_;
	}
	
	StringWriterPtr CrcService::commandServer(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		const string& strValue_ = nCommand.getCommand(1);
		const __i32 valueId_ = this->runServer(strValue_.c_str());
		stringWriter_.runString(strValue_, "strValue");
		stringWriter_.runInt32(valueId_, "valueId");
		return stringWriter_;
	}
	
	StringWriterPtr CrcService::commandDatabase(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		const string& strValue_ = nCommand.getCommand(1);
		const __i32 valueId_ = this->runDatabase(strValue_.c_str());
		stringWriter_.runString(strValue_, "strValue");
		stringWriter_.runInt32(valueId_, "valueId");
		return stringWriter_;
	}
	
	StringWriterPtr CrcService::commandTable(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		const string& strValue_ = nCommand.getCommand(1);
		const __i32 valueId_ = this->commandTable(strValue_.c_str());
		stringWriter_.runString(strValue_, "strValue");
		stringWriter_.runInt32(valueId_, "valueId");
		return stringWriter_;
	}
	
	StringWriterPtr CrcService::commandInfo(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		string className_("");
		__i32 classid_ = __classid<CrcService>(className_);
		stringWriter_.runString(className_, "className");
		stringWriter_.runInt32(classid_, "classId");
		return stringWriter_;
	}
	
	StringWriterPtr CrcService::commandInfo(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		string className_("");
		__i32 classid_ = __classid<CrcService>(className_);
		stringWriter_.runString(className_, "className");
		stringWriter_.runInt32(classid_, "classId");
		return stringWriter_;
	}
#endif

	const __i64 CrcService::runId(const char * nName) const
	{
		TimeService& timeService_ = Singleton<TimeService>::instance();
		__i64 seconds_ = timeService_.getLocalTime();
		seconds_ /= 10; __i64 result_ = this->runCommon(nName);
		result_ <<= 32; result_ += seconds_;
		return result_;
	}

	const __i64 CrcService::runId(__i32 nId) const
	{
		TimeService& timeService_ = Singleton<TimeService>::instance();
		__i64 seconds_ = timeService_.getLocalTime();
		seconds_ /= 10; __i64 result_ = nId;
		result_ <<= 32; result_ += seconds_;
		return result_;
	}

	const __i32 CrcService::runCommon(const char * nName) const
	{
		return this->hashString(nName, 0x100);
	}

	const __i32 CrcService::runComputer() const
	{
		//1282682146
		return this->hashString("computer", 0x100);
	}

	const __i32 CrcService::runCellphone() const
	{
		//318023319
		return this->hashString("cellphone", 0x150);
	}

	const __i32 CrcService::runName(const char * nName) const
	{
		return this->hashString(nName, 0x50);
	}
	
	const __i32 CrcService::runPassward(const char * nName) const
	{
		return this->hashString(nName, 0x300);
	}

	const __i32 CrcService::runCluster(const char * nName) const
	{
		return this->hashString(nName, 0x100);
	}

	const __i32 CrcService::runServer(const char * nName) const
	{
		return this->hashString(nName, 0x150);
	}

	const __i32 CrcService::runDatabase(const char * nName) const
	{
		return this->hashString(nName, 0x200);
	}

	const __i32 CrcService::runTable(const char * nName) const
	{
		return this->hashString(nName, 0x250);
	}

	const  __i32 CrcService::hashString(const char * nKey, __i16 nOffset) const
	{
		__i32 seed1 = 0x7FED7FED;
		__i32 seed2 = 0xEEEEEEEE;

		__i32 ch;

		while (*nKey != 0) {
			ch = toupper(*nKey++, locale());
			seed1 = crypt_buf[nOffset + ch] ^ (seed1 + seed2);
			seed2 = ch + seed1 + seed2 + (seed2 << 5) + 3;
		}

		return seed1;
	}
	
	CrcService * CrcService::getCrcService()
	{
		CrcService& crcService_ = Singleton<CrcService>::instance();
		return (&crcService_);
	}

	void CrcService::runLuaApi()
	{
		LuaService& luaService_ = Singleton<LuaService>::instance();
		luaService_.runClass<CrcService>("CrcService");
		luaService_.runFun(&CrcService::getCrcService, "getCrcService");
		luaService_.runMethod<CrcService>(&CrcService::runCommon, "runCommon");
		luaService_.runMethod<CrcService>(&CrcService::runComputer, "runComputer");
		luaService_.runMethod<CrcService>(&CrcService::runCellphone, "runCellphone");
		luaService_.runMethod<CrcService>(&CrcService::runName, "runName");
		luaService_.runMethod<CrcService>(&CrcService::runPassward, "runPassward");
		luaService_.runMethod<CrcService>(&CrcService::runCluster, "runCluster");
		luaService_.runMethod<CrcService>(&CrcService::runServer, "runServer");
		luaService_.runMethod<CrcService>(&CrcService::runDatabase, "runDatabase");
		luaService_.runMethod<CrcService>(&CrcService::runTable, "runTable");
	}

	bool CrcService::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunLuaApi.connect(boost::bind(&CrcService::runLuaApi, this));
	#ifdef __CONSOLE__
		this->registerCommand("info", std::bind(&CrcService::commandInfo, this, _1));
		this->registerCommand("nameId", std::bind(&CrcService::commandNameId, this, _1));
		this->registerCommand("intId", std::bind(&CrcService::commandIntId, this, _1));
		this->registerCommand("common", std::bind(&CrcService::commandCommon, this, _1));
		this->registerCommand("computer", std::bind(&CrcService::commandComputer, this, _1));
		this->registerCommand("cellphone", std::bind(&CrcService::commandCellphone, this, _1));
		this->registerCommand("name", std::bind(&CrcService::commandName, this, _1));
		this->registerCommand("passward", std::bind(&CrcService::commandPassward, this, _1));
		this->registerCommand("cluster", std::bind(&CrcService::commandCluster, this, _1));
		this->registerCommand("server", std::bind(&CrcService::commandServer, this, _1));
		this->registerCommand("database", std::bind(&CrcService::commandDatabase, this, _1));
		this->registerCommand("table", std::bind(&CrcService::commandTable, this, _1));
	#endif
		return true;
	}
	
	CrcService::CrcService()
	{
	}

	CrcService::~CrcService()
	{
	}
	
	static Preinit0<CrcService> sCrcServicePreinit;
}
