#pragma once

#ifndef __WINDOW__
#include <cxxabi.h>
#include <malloc.h>
#endif

namespace std {

	class __funapi CrcService : public IService
	{
	public:
	#ifdef __CONSOLE__
		StringWriterPtr runCommand(std::list<std::string>& nCommand);
	#endif
		__i64 runId(const char * nName);
		__i64 runId(__i32 nId);
		__i32 runCommon(const char * nName);
		__i32 runComputer();
		__i32 runCellphone();
		__i32 runName(const char * nName);
		__i32 runPassward(const char * nName);
		__i32 runCluster(const char * nName);
		__i32 runServer(const char * nName);
		__i32 runDatabase(const char * nName);
		__i32 runTable(const char * nName);
		template <class T>
		__i32 runClassId(string& nClassName)
		{
			__i32 result_ = 0;
			LogService& logService_ = Singleton<LogService>::instance();
		#ifdef __WINDOW__
			nClassName = typeid(T).name();
			nClassName = nClassName.substr(6);
			result_ = this->runName(nClassName.c_str());
		#else
			const char * className_ = typeid(T).name();
			char * realName_ = abi::__cxa_demangle(className_, 0, 0, 0);
			nClassName = realName_;
			result_ = this->runName(realName_);
			::free(realName_);
		#endif
			return result_;
		}
		
		static CrcService * crcService();
		void runLuaApi();
		
		CrcService();
		~CrcService();

	private:
		__i32 hashString(const char * nKey, __i16 nOffset);
	};

}
