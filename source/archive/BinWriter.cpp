#include "../Include.h"

#ifdef __COCOS2DX__
#include <cocos2d.h>
#endif

namespace std {

	void BinWriter::runBool(bool& nValue, const char * nName, const bool nOptimal)
	{
		__i8 value_ = ((true == nValue) ? 1 : 0);
		this->runInt8(value_, nName, nOptimal);
	}

	void BinWriter::runInt8(__i8& nValue, const char * nName, const __i8 nOptimal)
	{
		mStream.write((char *)(&nValue), sizeof(__i8));
	}

	void BinWriter::runInt8s(list<__i8>& nValue, const char * nNames, const char * nName)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		list<__i8>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i8 t_ = (*it);
			this->runInt8(t_, nName);
		}
	}

	void BinWriter::runInt8Count(__i8& nValue, const char * nName, const __i32 nCount, const __i8 nOptimal)
	{
		this->runInt8(nValue, nName);
	}

	void BinWriter::runInt8sCount(list<__i8>& nValue, const char * nName, const __i32 nCount)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		list<__i8>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i8 t_ = (*it);
			this->runInt8(t_, nName);
		}
	}

	void BinWriter::runInt8Semi(list<__i8>& nValue, const char * nName)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		list<__i8>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i8 t_ = (*it);
			this->runInt8(t_, nName);
		}
	}

	void BinWriter::runInt16(__i16& nValue, const char * nName, const __i16 nOptimal)
	{
		mStream.write((char *)(&nValue), sizeof(__i16));
	}

	void BinWriter::runInt16s(list<__i16>& nValue, const char * nNames, const char * nName)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		list<__i16>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i16 t_ = (*it);
			this->runInt16(t_, nName);
		}
	}

	void BinWriter::runInt16Count(__i16& nValue, const char * nName, const __i32 nCount, const __i16 nOptimal)
	{
		this->runInt16(nValue, nName);
	}

	void BinWriter::runInt16sCount(list<__i16>& nValue, const char * nName, const __i32 nCount)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		list<__i16>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i16 t_ = (*it);
			this->runInt16(t_, nName);
		}
	}

	void BinWriter::runInt16Semi(list<__i16>& nValue, const char * nName)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		list<__i16>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i16 t_ = (*it);
			this->runInt16(t_, nName);
		}
	}

	void BinWriter::runInt32(__i32& nValue, const char * nName, const __i32 nOptimal)
	{
		mStream.write((char *)(&nValue), sizeof(__i32));
	}

	void BinWriter::runInt32s(list<__i32>& nValue, const char * nNames, const char * nName)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		list<__i32>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i32 t_ = (*it);
			this->runInt32(t_, nName);
		}
	}

	void BinWriter::runInt32Count(__i32& nValue, const char * nName, const __i32 nCount, const __i32 nOptimal)
	{
		mStream.write((char *)(&nValue), sizeof(__i32));
	}

	void BinWriter::runInt32sCount(list<__i32>& nValue, const char * nName, const __i32 nCount)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		list<__i32>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i32 t_ = (*it);
			this->runInt32(t_, nName);
		}
	}

	void BinWriter::runInt32Semi(list<__i32>& nValue, const char * nName)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		list<__i32>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i32 t_ = (*it);
			this->runInt32(t_, nName);
		}
	}

	void BinWriter::runCrc32(__i32& nValue, const char * nName, const __i32 nOptimal)
	{
		this->runInt32(nValue, nName);
	}

	void BinWriter::runCrc32s(list<__i32>& nValue, const char * nNames, const char * nName)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		list<__i32>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i32 t_ = (*it);
			this->runInt32(t_, nName);
		}
	}

	void BinWriter::runCrc32Count(__i32& nValue, const char * nName, const __i32 nCount, const __i32 nOptimal)
	{
		this->runInt32(nValue, nName);
	}

	void BinWriter::runCrc32sCount(list<__i32>& nValue, const char * nName, const __i32 nCount)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		list<__i32>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i32 t_ = (*it);
			this->runInt32(t_, nName);
		}
	}

	void BinWriter::runCrc32Semi(list<__i32>& nValue, const char * nName)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		list<__i32>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i32 t_ = (*it);
			this->runInt32(t_, nName);
		}
	}

	void BinWriter::runInt64(__i64& nValue, const char * nName, const __i64 nOptimal)
	{
		mStream.write((char *)(&nValue), sizeof(__i64));
	}

	void BinWriter::runInt64s(list<__i64>& nValue, const char * nNames, const char * nName)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		list<__i64>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i64 t_ = (*it);
			this->runInt64(t_, nName);
		}
	}

	void BinWriter::runInt64Count(__i64& nValue, const char * nName, const __i32 nCount, const __i64 nOptimal)
	{
		this->runInt64(nValue, nName);
	}

	void BinWriter::runInt64sCount(list<__i64>& nValue, const char * nName, const __i32 nCount)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		list<__i64>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i64 t_ = (*it);
			this->runInt64(t_, nName);
		}
	}

	void BinWriter::runInt64Semi(list<__i64>& nValue, const char * nName)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		list<__i64>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			__i64 t_ = (*it);
			this->runInt64(t_, nName);
		}
	}

	void BinWriter::runString(string& nValue, const char * nName, const char * nOptimal)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		mStream.write((char *)(&nValue[0]), sizeof(char) * count_);
	}

	void BinWriter::runStrings(list<string>& nValue, const char * nNames, const char * nName)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		list<string>::iterator it = nValue.begin();
		for ( ; it != nValue.end(); ++it ) {
			string& tempStr = (*it);
			this->runString(tempStr, nName);
		}
	}

	void BinWriter::runStringCount(string& nValue, const char * nName, const __i32 nCount, const char * nOptimal)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		mStream.write((char *)(&nValue[0]), sizeof(char)* count_);
	}

	void BinWriter::runStringsCount(list<string>& nValue, const char * nName, const __i32 nCount)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		list<string>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			string& tempStr = (*it);
			this->runString(tempStr, nName);
		}
	}

	void BinWriter::runStringSemi(list<string>& nValue, const char * nName)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		list<string>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			string& tempStr = (*it);
			this->runString(tempStr, nName);
		}
	}

	void BinWriter::runFloat(float& nValue, const char * nName, const float nOptimal)
	{
		mStream.write((char *)(&nValue), sizeof(float));
	}

	void BinWriter::runFloats(list<float>& nValue, const char * nNames, const char * nName)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		list<float>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			float& value_ = (*it);
			this->runFloat(value_, nName);
		}
	}

	void BinWriter::runFloatCount(float& nValue, const char * nName, const __i32 nCount, const float nOptimal)
	{
		mStream.write((char *)(&nValue), sizeof(float));
	}

	void BinWriter::runFloatsCount(list<float>& nValue, const char * nName, const __i32 nCount)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		list<float>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			float& value_ = (*it);
			this->runFloat(value_, nName);
		}
	}

	void BinWriter::runFloatSemi(list<float>& nValue, const char * nName)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		list<float>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			float& value_ = (*it);
			this->runFloat(value_, nName);
		}
	}

	void BinWriter::runDouble(double& nValue, const char * nName, const double nOptimal)
	{
		mStream.write((char *)(&nValue), sizeof(double));
	}

	void BinWriter::runDoubles(list<double>& nValue, const char * nNames, const char * nName)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		list<double>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			double& value_ = (*it);
			this->runDouble(value_, nName);
		}
	}

	void BinWriter::runDoubleCount(double& nValue, const char * nName, const __i32 nCount, const double nOptimal)
	{
		mStream.write((char *)(&nValue), sizeof(double));
	}

	void BinWriter::runDoublesCount(list<double>& nValue, const char * nName, const __i32 nCount)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		list<double>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			double& value_ = (*it);
			this->runDouble(value_, nName);
		}
	}

	void BinWriter::runDoubleSemi(list<double>& nValue, const char * nName)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		list<double>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			double& value_ = (*it);
			this->runDouble(value_, nName);
		}
	}

	bool BinWriter::openUrl(const char * nUrl)
	{
#ifdef __COCOS2DX__
		string writePath = FileUtils::getInstance()->getWritablePath();
		writePath += "/"; writePath += nUrl;
		mStream.open(writePath.c_str(), ios::binary | ios::out);
		if (mStream.is_open()) {
			return true;
		}
		return false;
#else
		mStream.open(nUrl, ios::binary | ios::out);
		if (mStream.is_open()) {
			return true;
		}
		return false;
#endif
	}

	void BinWriter::selectStream(const char * nStreamName) const
	{
	}

	__i32 BinWriter::pushStream(const char * nName)
	{
		return 0;
	}

	void BinWriter::popStream()
	{
	}

	void BinWriter::runWrite(char * nValue, __i32 nLength)
	{
		mStream.write(nValue, nLength);
	}

	void BinWriter::runSeek(__i32 nPos)
	{
		mStream.seekp(nPos, ios::beg);
	}

	__i32 BinWriter::runTell()
	{
		return static_cast<__i32>(mStream.tellp());
	}

	void BinWriter::runClose()
	{
		if (mStream.is_open()) {
			mStream.close();
		}
	}

	BinWriter::BinWriter()
	{
	}

	BinWriter::~BinWriter()
	{
	}

}

