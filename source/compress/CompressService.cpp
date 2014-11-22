#include "../../include/Include.h"
#include "../../dependence/bzlib/bzlib.h"

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
		LuaService& luaService_ = Singleton<LuaService>::instance();
		luaService_.runClass<CompressService>("CompressService");
		luaService_.runMethod<CompressService>(&CompressService::runBZip2, "runBZip2");
		luaService_.runMethod<CompressService>(&CompressService::unBZip2, "unBZip2");
		
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}

	bool CompressService::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&CompressService::runInit, this));

		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));

		return true;
	}

	void CompressService::runInit()
	{
		CompressService::runScript();

		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("fihish!"));
	}

	CompressService::CompressService()
	{
	}

	CompressService::~CompressService()
	{
	}
	
	static Preinit<CompressService> sCompressServicePreinit;

}

