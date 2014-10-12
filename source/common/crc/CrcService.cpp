#include "../Common.h"

#include "crypt_buf.h"

#ifdef __CRC__
namespace std {

	__i64 CrcService::runId(const char * nName)
	{
		TimeService& timeService_ = Singleton<TimeService>::instance();
		__i64 seconds_ = timeService_.getNowSecond();
		seconds_ /= 10;
		__i64 result_ = this->runCommon(nName);
		result_ <<= 32;
		result_ += seconds_;
		return result_;
	}

	__i64 CrcService::runId(__i32 nId)
	{
		TimeService& timeService_ = Singleton<TimeService>::instance();
		__i64 seconds_ = timeService_.getNowSecond();
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

	void CrcService::runScript()
	{
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("CrcService run runScript!"));
	#endif
		LuaService& luaService_ = Singleton<LuaService>::instance();
		luaService_.runClass<CrcService>("CrcService");
		luaService_.runMethod<CrcService>(&CrcService::runCommon, "runCommon");
	#ifdef __LOG__
		logService_.logInfo(log_1("CrcService run runScript finish!"));
	#endif
	}

	bool CrcService::runPreinit()
	{
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("CrcService run runPreinit!"));
	#endif
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&CrcService::runInit, this));
	#ifdef __LOG__
		logService_.logInfo(log_1("CrcService run runPreinit finish!"));
	#endif
		return true;
	}

	void CrcService::runInit()
	{
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("CrcService run runInit!"));
	#endif
		CrcService::runScript();
	#ifdef __LOG__
		logService_.logInfo(log_1("CrcService run runInit finish!"));
	#endif
	}

	CrcService::CrcService()
	{
	}

	CrcService::~CrcService()
	{
	}
	
	static Preinit<CrcService> sCrcServicePreinit;
}
#endif

