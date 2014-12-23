#include "../Include.h"
#include "../../dependence/bzlib/bzlib.h"

namespace std {

#ifdef __CONSOLE__
	StringWriterPtr CompressService::commandInfo(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		string className_(""); 
		__i32 classid_ = __classinfo<CompressService>(className_);
		stringWriter_->runString(className_, "className");
		stringWriter_->runInt32(classid_, "classId");
		return stringWriter_;
	}
	
	StringWriterPtr CompressService::commandRunBZip2(const CommandArgs& nCommand)
	{
	}
	
	StringWriterPtr CompressService::commandUnBZip2(const CommandArgs& nCommand)
	{
	}
#endif
	
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
		this->registerCommand("info", std::bind(&CompressService::commandInfo, this, placeholders::_1));
		this->registerCommand("runBzip2", std::bind(&CompressService::commandRunBZip2, this, placeholders::_1));
		this->registerCommand("unBZip2", std::bind(&CompressService::commandUnBZip2, this, placeholders::_1));
	#endif
		return true;
	}

	CompressService::CompressService()
	{
	}

	CompressService::~CompressService()
	{
	}
	
	static Preinit0<CompressService> sCompressServicePreinit;

}

