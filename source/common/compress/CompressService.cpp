#include "../Common.h"
#include "bzlib/bzlib.h"

#ifdef __COMPRESS__
namespace std {

	void CompressService::runBZip2(char * nInBuf, __i32 nInSize, char * nOutBuf, __i32 * nOutSize)
	{
		unsigned int outSize = static_cast<unsigned int>(*nOutSize);
		BZ2_bzBuffToBuffCompress(nOutBuf, &outSize, nInBuf, nInSize, 1, 0, 0);
		(*nOutSize) = static_cast<__i32>(outSize);
	}

	void CompressService::unBZip2(char * nInBuf, __i32 nInSize, char * nOutBuf, __i32 * nOutSize)
	{
		unsigned int outSize = static_cast<unsigned int>(*nOutSize);
		BZ2_bzBuffToBuffDecompress(nOutBuf, &outSize, nInBuf, nInSize, 0, 0);
		(*nOutSize) = static_cast<__i32>(outSize);
	}

	void CompressService::runScript()
	{
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("CompressService run runScript!"));

		LuaService& luaService_ = Singleton<LuaService>::instance();
		luaService_.runClass<CompressService>("CompressService");
		luaService_.runMethod<CompressService>(&CompressService::runBZip2, "runBZip2");
		luaService_.runMethod<CompressService>(&CompressService::unBZip2, "unBZip2");
		
		logService_.logInfo(log_1("CompressService run runScript finish!"));
	}

	void CompressService::runPreinit()
	{
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("CompressService run runPreinit!"));

		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&CompressService::runInit, this));
		
		logService_.logInfo(log_1("CompressService run runPreinit finish!"));
	}

	void CompressService::runInit()
	{
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("CompressService run runInit!"));

		CompressService::runScript();
		
		logService_.logInfo(log_1("CompressService run runInit fihish!"));
	}

	CompressService::CompressService()
	{
	}

	CompressService::~CompressService()
	{
	}

}
#endif
