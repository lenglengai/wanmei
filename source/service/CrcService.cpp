#include "../Include.h"

#include "crypt_buf.h"

namespace std {

#ifdef __CONSOLE__
	StringWriterPtr CrcService::runCommand(std::list<std::string>& nCommand)
	{
		StringWriterPtr stringWriter(new StringWriter());
		std::string& command_ = nCommand.front();
		if ("-runId" == command_) {
			nCommand.pop_front();
			command_ = nCommand.front();
			__i64 value_ = this->runId(command_.c_str());
			stringWriter->runInt64(value_, "runId");
		} else if ("-runCommon" == command_) {
			nCommand.pop_front();
			command_ = nCommand.front();
			__i64 value_ = this->runCommon(command_.c_str());
			stringWriter->runInt64(value_, "runCommon");
		} else if ("-runComputer" == command_) {
			__i64 value_ = this->runComputer();
			stringWriter->runInt64(value_, "runComputer");
		} else if ("-runCellphone" == command_) {
			__i64 value_ = this->runCellphone();
			stringWriter->runInt64(value_, "runCellphone");
		} else if ("-runName" == command_) {
			nCommand.pop_front();
			command_ = nCommand.front();
			__i64 value_ = this->runName(command_.c_str());
			stringWriter->runInt64(value_, "runName");
		} else if ("-runPassward" == command_) {
			nCommand.pop_front();
			command_ = nCommand.front();
			__i64 value_ = this->runPassward(command_.c_str());
			stringWriter->runInt64(value_, "runPassward");
		} else if ("-runCluster" == command_) {
			nCommand.pop_front();
			command_ = nCommand.front();
			__i64 value_ = this->runCluster(command_.c_str());
			stringWriter->runInt64(value_, "runCluster");
		} else if ("-runServer" == command_) {
			nCommand.pop_front();
			command_ = nCommand.front();
			__i64 value_ = this->runServer(command_.c_str());
			stringWriter->runInt64(value_, "runServer");
		} else if ("-runDatabase" == command_) {
			nCommand.pop_front();
			command_ = nCommand.front();
			__i64 value_ = this->runDatabase(command_.c_str());
			stringWriter->runInt64(value_, "runDatabase");
		} else if ("-runTable" == command_) {
			nCommand.pop_front();
			command_ = nCommand.front();
			__i64 value_ = this->runTable(command_.c_str());
			stringWriter->runInt64(value_, "runTable");
		} else {
			stringWriter->runString("CrcService", "do nothing");
		}
		return stringWriter;
	}
#endif

	__i64 CrcService::runId(const char * nName)
	{
		TimeService& timeService_ = Singleton<TimeService>::instance();
		__i64 seconds_ = timeService_.getLocalTime();
		seconds_ /= 10;
		__i64 result_ = this->runCommon(nName);
		result_ <<= 32;
		result_ += seconds_;
		return result_;
	}

	__i64 CrcService::runId(__i32 nId)
	{
		TimeService& timeService_ = Singleton<TimeService>::instance();
		__i64 seconds_ = timeService_.getLocalTime();
		seconds_ /= 10;
		__i64 result_ = nId;
		result_ <<= 32;
		result_ += seconds_;
		return result_;
	}

	__i32 CrcService::runCommon(const char * nName)
	{
		return this->hashString(nName, 0x100);
	}

	__i32 CrcService::runComputer()
	{
		//1282682146
		return this->hashString("computer", 0x100);
	}

	__i32 CrcService::runCellphone()
	{
		//318023319
		return this->hashString("cellphone", 0x150);
	}

	__i32 CrcService::runName(const char * nName)
	{
		return this->hashString(nName, 0x50);
	}
	
	__i32 CrcService::runPassward(const char * nName)
	{
		return this->hashString(nName, 0x300);
	}

	__i32 CrcService::runCluster(const char * nName)
	{
		return this->hashString(nName, 0x100);
	}

	__i32 CrcService::runServer(const char * nName)
	{
		return this->hashString(nName, 0x150);
	}

	__i32 CrcService::runDatabase(const char * nName)
	{
		return this->hashString(nName, 0x200);
	}

	__i32 CrcService::runTable(const char * nName)
	{
		return this->hashString(nName, 0x250);
	}

	__i32 CrcService::hashString(const char * nKey, __i16 nOffset)
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

	void CrcService::runLuaApi()
	{
		LuaService& luaService_ = Singleton<LuaService>::instance();
		luaService_.runClass<CrcService>("CrcService");
		luaService_.runFun(&CrcService::crcService, "crcService");
		luaService_.runMethod<CrcService>(&CrcService::runCommon, "runCommon");
	}

	CrcService::CrcService()
	{
	}

	CrcService::~CrcService()
	{
	}
	
	static Preinit0<CrcService> sCrcServicePreinit;
}
