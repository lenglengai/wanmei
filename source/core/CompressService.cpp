#include "../Include.h"
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

	void CompressService::runLuaApi()
	{
		LuaService& luaService_ = Singleton<LuaService>::instance();
		luaService_.runClass<CompressService>("CompressService");
		luaService_.runFun(&CompressService::getCompressService, "getCompressService");
		luaService_.runMethod<CompressService>(&CompressService::runBZip2, "runBZip2");
		luaService_.runMethod<CompressService>(&CompressService::unBZip2, "unBZip2");
	}

	bool CompressService::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunLuaApi.connect(boost::bind(&CompressService::runLuaApi, this));
	#ifdef __CONSOLE__
		this->registerCommand("info", std::bind(&CrcService::commandInfo, this, _1));
		this->registerCommand("runBzip2", std::bind(&CrcService::commandRunBZip2, this, _1));
		this->registerCommand("unBZip2", std::bind(&CrcService::commandUnBZip2, this, _1));
	#endif
		return true;
	}

	CompressService::CompressService()
	{
	}

	CompressService::~CompressService()
	{
	}
	
	static Preinit<CompressService> sCompressServicePreinit;

}

