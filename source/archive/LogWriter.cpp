#include "../../include/Include.h"

namespace std {

	void LogWriter::runBool(bool& nValue, const char * nName, bool nOptimal)
	{
		mValue += "["; mValue += nName;  mValue += ":";
		mValue += __convert<std::string, bool>(nValue); 
		mValue += "]";
	}

	void LogWriter::runInt8(__i8& nValue, const char * nName, __i8 nOptimal)
	{
		mValue += "["; mValue += nName;  mValue += ":";
		mValue += __convert<std::string, __i8>(nValue); 
		mValue += "]";
	}

	void LogWriter::runInt8s(list<__i8>& nValue, const char * nNames, const char * nName)
	{
		mValue += "["; mValue += nNames;  mValue += ":";
		std::list<__i8>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i8 t_ = (*it);
			this->runInt8(t_, nName);
		}
		mValue += "]";
	}

	void LogWriter::runInt8Count(__i8& nValue, const char * nName, __i32 nCount, __i8 nOptimal)
	{
		this->runInt8(nValue, nName);
	}

	void LogWriter::runInt8sCount(list<__i8>& nValue, const char * nName, __i32 nCount)
	{
		mValue += "[";
		std::list<__i8>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i8 t_ = (*it);
			this->runInt8(t_, nName);
		}
		mValue += "]";
	}

	void LogWriter::runInt8Semi(list<__i8>& nValue, const char * nName)
	{
		mValue += "[";
		std::list<__i8>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i8 t_ = (*it);
			this->runInt8(t_, nName);
		}
		mValue += "]";
	}

	void LogWriter::runInt16(__i16& nValue, const char * nName, __i16 nOptimal)
	{
		mValue += "["; mValue += nName;  mValue += ":";
		mValue += __convert<std::string, __i16>(nValue); 
		mValue += "]";
	}

	void LogWriter::runInt16s(std::list<__i16>& nValue, const char * nNames, const char * nName)
	{
		mValue += "["; mValue += nNames;
		std::list<__i16>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i16 t_ = (*it);
			this->runInt16(t_, nName);
		}
		mValue += "]";
	}

	void LogWriter::runInt16Count(__i16& nValue, const char * nName, __i32 nCount, __i16 nOptimal)
	{
		this->runInt16(nValue, nName);
	}

	void LogWriter::runInt16sCount(std::list<__i16>& nValue, const char * nName, __i32 nCount)
	{
		mValue += "[";
		std::list<__i16>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i16 t_ = (*it);
			this->runInt16(t_, nName);
		}
		mValue += "]";
	}

	void LogWriter::runInt16Semi(std::list<__i16>& nValue, const char * nName)
	{
		mValue += "[";
		std::list<__i16>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i16 t_ = (*it);
			this->runInt16(t_, nName);
		}
		mValue += "]";
	}

	void LogWriter::runInt32(__i32& nValue, const char * nName, __i32 nOptimal)
	{
		mValue += "["; mValue += nName;  mValue += ":";
		mValue += __convert<std::string, __i32>(nValue); 
		mValue += "]";
	}

	void LogWriter::runInt32s(std::list<__i32>& nValue, const char * nNames, const char * nName)
	{
		mValue += "["; mValue += nNames;
		std::list<__i32>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i32 t_ = (*it);
			this->runInt32(t_, nName);
		}
		mValue += "]";
	}

	void LogWriter::runInt32Count(__i32& nValue, const char * nName, __i32 nCount, __i32 nOptimal)
	{
		mValue += "["; mValue += nName;  mValue += ":";
		mValue += __convert<std::string, __i64>(nValue); 
		mValue += "]";
	}

	void LogWriter::runInt32sCount(list<__i32>& nValue, const char * nName, __i32 nCount)
	{
		mValue += "[";
		std::list<__i32>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i32 t_ = (*it);
			this->runInt32(t_, nName);
		}
		mValue += "]";
	}

	void LogWriter::runInt32Semi(list<__i32>& nValue, const char * nName)
	{
		mValue += "[";
		std::list<__i32>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i32 t_ = (*it);
			this->runInt32(t_, nName);
		}
		mValue += "]";
	}

	void LogWriter::runCrc32(__i32& nValue, const char * nName, __i32 nOptimal)
	{
		mValue += "["; mValue += nName;  mValue += ":";
		mValue += __convert<std::string, __i32>(nValue); 
		mValue += "]";
	}

	void LogWriter::runCrc32s(list<__i32>& nValue, const char * nNames, const char * nName)
	{
		mValue += "["; mValue += nNames;
		std::list<__i32>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i32 t_ = (*it);
			this->runInt32(t_, nName);
		}
		mValue += "]";
	}

	void LogWriter::runCrc32Count(__i32& nValue, const char * nName, __i32 nCount, __i32 nOptimal)
	{
		this->runInt32(nValue, nName);
	}

	void LogWriter::runCrc32sCount(list<__i32>& nValue, const char * nName, __i32 nCount)
	{
		mValue += "[";
		std::list<__i32>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i32 t_ = (*it);
			this->runInt32(t_, nName);
		}
		mValue += "]";
	}

	void LogWriter::runCrc32Semi(list<__i32>& nValue, const char * nName)
	{
		mValue += "[";
		std::list<__i32>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i32 t_ = (*it);
			this->runInt32(t_, nName);
		}
		mValue += "]";
	}

	void LogWriter::runInt64(__i64& nValue, const char * nName, __i64 nOptimal)
	{
		mValue += "["; mValue += nName;  mValue += ":";
		mValue += __convert<std::string, __i64>(nValue); 
		mValue += "]";
	}

	void LogWriter::runInt64s(list<__i64>& nValue, const char * nNames, const char * nName)
	{
		mValue += "["; mValue += nNames;
		std::list<__i64>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i64 t_ = (*it);
			this->runInt64(t_, nName);
		}
		mValue += "]";
	}

	void LogWriter::runInt64Count(__i64& nValue, const char * nName, __i32 nCount, __i64 nOptimal)
	{
		mValue += "["; mValue += nName;  mValue += ":";
		mValue += __convert<std::string, __i64>(nValue); 
		mValue += "]";
	}

	void LogWriter::runInt64sCount(std::list<__i64>& nValue, const char * nName, __i32 nCount)
	{
		mValue += "[";
		std::list<__i64>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i64 t_ = (*it);
			this->runInt64(t_, nName);
		}
		mValue += "]";
	}

	void LogWriter::runInt64Semi(list<__i64>& nValue, const char * nName)
	{
		mValue += "[";
		std::list<__i64>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i64 t_ = (*it);
			this->runInt64(t_, nName);
		}
		mValue += "]";
	}

	void LogWriter::runString(std::string& nValue, const char * nName, const char * nOptimal)
	{
		mValue += "["; mValue += nName;  mValue += ":";
		mValue += nValue; mValue += "]";
	}

	void LogWriter::runStrings(std::list<std::string>& nValue, const char * nNames, const char * nName)
	{
		mValue += "["; mValue += nNames;
		std::list<std::string>::iterator it = nValue.begin();
		for ( ; it != nValue.end(); ++it ) {
			std::string& tempStr = (*it);
			this->runString(tempStr, nName);
		}
		mValue += "]";
	}

	void LogWriter::runStringCount(std::string& nValue, const char * nName, __i32 nCount, const char * nOptimal)
	{
		mValue += "["; mValue += nName;  mValue += ":";
		mValue += nValue; mValue += "]";
	}

	void LogWriter::runStringsCount(std::list<std::string>& nValue, const char * nName, __i32 nCount)
	{
		mValue += "[";
		std::list<std::string>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			std::string& tempStr = (*it);
			this->runString(tempStr, nName);
		}
		mValue += "]";
	}

	void LogWriter::runStringSemi(std::list<std::string>& nValue, const char * nName)
	{
		mValue += "[";
		std::list<std::string>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			std::string& tempStr = (*it);
			this->runString(tempStr, nName);
		}
		mValue += "]";
	}

	void LogWriter::runFloat(float& nValue, const char * nName, float nOptimal)
	{
		mValue += "["; mValue += nName;  mValue += ":";
		mValue += __convert<std::string, float>(nValue); 
		mValue += "]";
	}

	void LogWriter::runFloats(list<float>& nValue, const char * nNames, const char * nName)
	{
		mValue += "["; mValue += nNames;
		std::list<float>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			float& value_ = (*it);
			this->runFloat(value_, nName);
		}
		mValue += "]";
	}

	void LogWriter::runFloatCount(float& nValue, const char * nName, __i32 nCount, float nOptimal)
	{
		mValue += "["; mValue += nName;  mValue += ":";
		mValue += __convert<std::string, float>(nValue); 
		mValue += "]";
	}

	void LogWriter::runFloatsCount(std::list<float>& nValue, const char * nName, __i32 nCount)
	{
		mValue += "[";
		std::list<float>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			float& value_ = (*it);
			this->runFloat(value_, nName);
		}
		mValue += "]";
	}

	void LogWriter::runFloatSemi(std::list<float>& nValue, const char * nName)
	{
		mValue += "[";
		std::list<float>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			float& value_ = (*it);
			this->runFloat(value_, nName);
		}
		mValue += "]";
	}

	void LogWriter::runDouble(double& nValue, const char * nName, double nOptimal)
	{
		mValue += "["; mValue += nName;  mValue += ":";
		mValue += __convert<std::string, double>(nValue); 
		mValue += "]";
	}

	void LogWriter::runDoubles(std::list<double>& nValue, const char * nNames, const char * nName)
	{
		mValue += "["; mValue += nNames;
		std::list<double>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			double& value_ = (*it);
			this->runDouble(value_, nName);
		}
		mValue += "]";
	}

	void LogWriter::runDoubleCount(double& nValue, const char * nName, __i32 nCount, double nOptimal)
	{
		mValue += "["; mValue += nName;  mValue += ":";
		mValue += __convert<std::string, double>(nValue); 
		mValue += "]";
	}

	void LogWriter::runDoublesCount(std::list<double>& nValue, const char * nName, __i32 nCount)
	{
		mValue += "[";
		std::list<double>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			double& value_ = (*it);
			this->runDouble(value_, nName);
		}
		mValue += "]";
	}

	void LogWriter::runDoubleSemi(list<double>& nValue, const char * nName)
	{
		mValue += "[";
		std::list<double>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			double& value_ = (*it);
			this->runDouble(value_, nName);
		}
		mValue += "]";
	}

	bool LogWriter::openUrl(const char * nUrl)
	{
		return true;
	}

	void LogWriter::selectStream(const char * nStreamName)
	{
	}

	__i32 LogWriter::pushStream(const char * nName)
	{
		return 0;
	}

	void LogWriter::popStream()
	{
	}

	void LogWriter::runClose()
	{
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1(mValue));
	}

	LogWriter::LogWriter()
	{
	}

	LogWriter::~LogWriter()
	{
	}

}
