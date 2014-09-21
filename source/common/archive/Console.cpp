#include "../DefInc.h"

#include "Console.h"

#include <iostream>

#ifdef __ARCHIVE__
namespace std {

	void Console::runBool(bool& nValue, const char * nName, bool nOptimal)
	{
		std::cout << "[" << nName << ":" << nValue << "]" << std::endl;
	}

	void Console::runInt8(__i8& nValue, const char * nName, __i8 nOptimal)
	{
		std::cout << "[" << nName << ":" << nValue << "]" << std::endl;
	}

	void Console::runInt8s(list<__i8>& nValue, const char * nNames, const char * nName)
	{
		std::cout << "[" << nNames  << ":";
		std::list<__i8>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i8 t_ = (*it);
			this->runInt8(t_, nName);
		}
		std::cout << "]" << std::endl;
	}

	void Console::runInt8Count(__i8& nValue, const char * nName, __i32 nCount, __i8 nOptimal)
	{
		this->runInt8(nValue, nName);
	}

	void Console::runInt8sCount(list<__i8>& nValue, const char * nName, __i32 nCount)
	{
		std::cout << "[";
		std::list<__i8>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i8 t_ = (*it);
			this->runInt8(t_, nName);
		}
		std::cout << "]" << std::endl;
	}

	void Console::runInt8Semi(list<__i8>& nValue, const char * nName)
	{
		std::cout << "[";
		std::list<__i8>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i8 t_ = (*it);
			this->runInt8(t_, nName);
		}
		std::cout << "]" << std::endl;
	}

	void Console::runInt16(__i16& nValue, const char * nName, __i16 nOptimal)
	{
		std::cout << "[" << nName << ":" << nValue << "]" << std::endl;
	}

	void Console::runInt16s(std::list<__i16>& nValue, const char * nNames, const char * nName)
	{
		std::cout << "[" << nNames;
		std::list<__i16>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i16 t_ = (*it);
			this->runInt16(t_, nName);
		}
		std::cout << "]" << std::endl;
	}

	void Console::runInt16Count(__i16& nValue, const char * nName, __i32 nCount, __i16 nOptimal)
	{
		this->runInt16(nValue, nName);
	}

	void Console::runInt16sCount(std::list<__i16>& nValue, const char * nName, __i32 nCount)
	{
		std::cout << "[" << nNames;
		std::list<__i16>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i16 t_ = (*it);
			this->runInt16(t_, nName);
		}
		std::cout << "]" << std::endl;
	}

	void Console::runInt16Semi(std::list<__i16>& nValue, const char * nName)
	{
		std::cout << "[" << nNames;
		std::list<__i16>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i16 t_ = (*it);
			this->runInt16(t_, nName);
		}
		std::cout << "]" << std::endl;
	}

	void Console::runInt32(__i32& nValue, const char * nName, __i32 nOptimal)
	{
		std::cout << "[" << nName << ":" << nValue << "]" << std::endl;
	}

	void Console::runInt32s(std::list<__i32>& nValue, const char * nNames, const char * nName)
	{
		std::cout << "[" << nNames;
		std::list<__i32>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i32 t_ = (*it);
			this->runInt32(t_, nName);
		}
		std::cout << "]" << std::endl;
	}

	void Console::runInt32Count(__i32& nValue, const char * nName, __i32 nCount, __i32 nOptimal)
	{
		mStream.write((char *)(&nValue), sizeof(__i32));
	}

	void Console::runInt32sCount(list<__i32>& nValue, const char * nName, __i32 nCount)
	{
		std::cout << "[" << nNames;
		std::list<__i32>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i32 t_ = (*it);
			this->runInt32(t_, nName);
		}
		std::cout << "]" << std::endl;
	}

	void Console::runInt32Semi(list<__i32>& nValue, const char * nName)
	{
		std::cout << "[" << nNames;
		std::list<__i32>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i32 t_ = (*it);
			this->runInt32(t_, nName);
		}
		std::cout << "]" << std::endl;
	}

	void Console::runCrc32(__i32& nValue, const char * nName, __i32 nOptimal)
	{
		std::cout << "[" << nName << ":" << nValue << "]" << std::endl;
	}

	void Console::runCrc32s(list<__i32>& nValue, const char * nNames, const char * nName)
	{
		std::cout << "[" << nNames;
		std::list<__i32>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i32 t_ = (*it);
			this->runInt32(t_, nName);
		}
		std::cout << "]" << std::endl;
	}

	void Console::runCrc32Count(__i32& nValue, const char * nName, __i32 nCount, __i32 nOptimal)
	{
		this->runInt32(nValue, nName);
	}


	void Console::runCrc32sCount(list<__i32>& nValue, const char * nName, __i32 nCount)
	{
		std::cout << "[" << nNames;
		std::list<__i32>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i32 t_ = (*it);
			this->runInt32(t_, nName);
		}
		std::cout << "]" << std::endl;
	}

	void Console::runCrc32Semi(list<__i32>& nValue, const char * nName)
	{
		std::cout << "[" << nNames;
		std::list<__i32>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i32 t_ = (*it);
			this->runInt32(t_, nName);
		}
		std::cout << "]" << std::endl;
	}

	void Console::runInt64(__i64& nValue, const char * nName, __i64 nOptimal)
	{
		std::cout << "[" << nName << ":" << nValue << "]" << std::endl;
	}

	void Console::runInt64s(list<__i64>& nValue, const char * nNames, const char * nName)
	{
		std::cout << "[" << nNames;
		std::list<__i64>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i64 t_ = (*it);
			this->runInt64(t_, nName);
		}
		std::cout << "]" << std::endl;
	}

	void Console::runInt64Count(__i64& nValue, const char * nName, __i32 nCount, __i64 nOptimal)
	{
		std::cout << "[" << nName << ":" << nValue << "]" << std::endl;
	}

	void Console::runInt64sCount(std::list<__i64>& nValue, const char * nName, __i32 nCount)
	{
		std::cout << "[" << nNames;
		std::list<__i64>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i64 t_ = (*it);
			this->runInt64(t_, nName);
		}
		std::cout << "]" << std::endl;
	}

	void Console::runInt64Semi(list<__i64>& nValue, const char * nName)
	{
		std::cout << "[" << nNames;
		std::list<__i64>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i64 t_ = (*it);
			this->runInt64(t_, nName);
		}
		std::cout << "]" << std::endl;
	}

	void Console::runString(std::string& nValue, const char * nName, const char * nOptimal)
	{
		std::cout << "[" << nName << ":" << nValue << "]" << std::endl;
	}

	void Console::runStrings(std::list<std::string>& nValue, const char * nNames, const char * nName)
	{
		std::cout << "[" << nNames;
		std::list<std::string>::iterator it = nValue.begin();
		for ( ; it != nValue.end(); ++it ) {
			std::string& tempStr = (*it);
			this->runString(tempStr, nName);
		}
		std::cout << "]" << std::endl;
	}

	void Console::runStringCount(std::string& nValue, const char * nName, __i32 nCount, const char * nOptimal)
	{
		std::cout << "[" << nName << ":" << nValue << "]" << std::endl;
	}

	void Console::runStringsCount(std::list<std::string>& nValue, const char * nName, __i32 nCount)
	{
		std::cout << "[" << nNames;
		std::list<std::string>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			std::string& tempStr = (*it);
			this->runString(tempStr, nName);
		}
		std::cout << "]" << std::endl;
	}

	void Console::runStringSemi(std::list<std::string>& nValue, const char * nName)
	{
		std::cout << "[" << nNames;
		std::list<std::string>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			std::string& tempStr = (*it);
			this->runString(tempStr, nName);
		}
		std::cout << "]" << std::endl;
	}

	void Console::runFloat(float& nValue, const char * nName, float nOptimal)
	{
		std::cout << "[" << nName << ":" << nValue << "]" << std::endl;
	}

	void Console::runFloats(list<float>& nValue, const char * nNames, const char * nName)
	{
		std::cout << "[" << nNames;
		std::list<float>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			float& value_ = (*it);
			this->runFloat(value_, nName);
		}
		std::cout << "]" << std::endl;
	}

	void Console::runFloatCount(float& nValue, const char * nName, __i32 nCount, float nOptimal)
	{
		std::cout << "[" << nName << ":" << nValue << "]" << std::endl;
	}

	void Console::runFloatsCount(std::list<float>& nValue, const char * nName, __i32 nCount)
	{
		std::cout << "[" << nNames;
		std::list<float>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			float& value_ = (*it);
			this->runFloat(value_, nName);
		}
		std::cout << "]" << std::endl;
	}

	void Console::runFloatSemi(std::list<float>& nValue, const char * nName)
	{
		std::cout << "[" << nNames;
		std::list<float>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			float& value_ = (*it);
			this->runFloat(value_, nName);
		}
		std::cout << "]" << std::endl;
	}

	void Console::runDouble(double& nValue, const char * nName, double nOptimal)
	{
		std::cout << "[" << nName << ":" << nValue << "]" << std::endl;
	}

	void Console::runDoubles(std::list<double>& nValue, const char * nNames, const char * nName)
	{
		std::cout << "[" << nNames;
		std::list<double>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			double& value_ = (*it);
			this->runDouble(value_, nName);
		}
		std::cout << "]" << std::endl;
	}

	void Console::runDoubleCount(double& nValue, const char * nName, __i32 nCount, double nOptimal)
	{
		std::cout << "[" << nName << ":" << nValue << "]" << std::endl;
	}

	void Console::runDoublesCount(std::list<double>& nValue, const char * nName, __i32 nCount)
	{
		std::cout << "[" << nNames;
		std::list<double>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			double& value_ = (*it);
			this->runDouble(value_, nName);
		}
		std::cout << "]" << std::endl;
	}

	void Console::runDoubleSemi(list<double>& nValue, const char * nName)
	{
		std::cout << "[" << nNames;
		std::list<double>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			double& value_ = (*it);
			this->runDouble(value_, nName);
		}
		std::cout << "]" << std::endl;
	}

	bool Console::openUrl(const char * nUrl)
	{
	}

	void Console::selectStream(const char * nStreamName)
	{
	}

	__i32 Console::pushStream(const char * nName)
	{
		return 0;
	}

	void Console::popStream()
	{
	}

	void Console::runClose()
	{
	}

	Console::Console()
	{
	}

	Console::~Console()
	{
	}

}
#endif
