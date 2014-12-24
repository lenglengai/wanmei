#include "../Include.h"
#include "../../dependence/bzlib/bzlib.h"

namespace std {

#ifdef __CONSOLE__
	const StringWriterPtr CompressService::commandInfo(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		string className_(""); 
		__i32 classid_ = __classinfo<CompressService>(className_);
		stringWriter_->runString(className_, "className");
		stringWriter_->runInt32(classid_, "classId");
		return stringWriter_;
	}
	
	const StringWriterPtr CompressService::commandRunBZip2(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		const string& strValue_ = nCommandArgs.getCommandArg(1);
		char buf[1024]; memset(buf, 0, sizeof(buf)); __i32 size_ = 0;
		char buf0[1024]; memset(buf0, 0, sizeof(buf0)); __i32 size0_ = 0;
		char * value_ = const_cast<char *>(strValue_.c_str());
		this->runBZip2(value_, strValue_.length(), buf, &size_);
		this->unBZip2(buf, size_, buf0, &size0_);
		bool suecess_ = false;
		if (strValue_ == buf0) {
			suecess_ = true;
		}
		stringWriter_->runString(strValue_, "strValue");
		stringWriter_->runString(buf0, "result");
		stringWriter_->runBool(suecess_, "buf0");

		return stringWriter_;
	}
#endif
	
	void CompressService::runBZip2(char * nInBuf, const __i32 nInSize, char * nOutBuf, __i32 * nOutSize)
	{
		unsigned int outSize = static_cast<unsigned int>(*nOutSize);
		BZ2_bzBuffToBuffCompress(nOutBuf, &outSize, nInBuf, nInSize, 1, 0, 0);
		(*nOutSize) = static_cast<__i32>(outSize);
	}

	void CompressService::unBZip2(char * nInBuf, const __i32 nInSize, char * nOutBuf, __i32 * nOutSize)
	{
		unsigned int outSize = static_cast<unsigned int>(*nOutSize);
		BZ2_bzBuffToBuffDecompress(nOutBuf, &outSize, nInBuf, nInSize, 0, 0);
		(*nOutSize) = static_cast<__i32>(outSize);
	}
	
	CompressService * CompressService::getCompressService()
	{
		CompressService& compressService_ = Singleton<CompressService>::instance();
		return (&compressService_);
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

