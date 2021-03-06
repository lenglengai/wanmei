#include "../Include.h"

#ifdef __COCOS2DX__
#include <cocos2d.h>
#endif

namespace std {

	void BinReader::runBool(bool& nValue, const char * nName, const bool nOptimal)
	{
		__i8 value_ = 0;
		this->runInt8(value_, nName, nOptimal);
		nValue = ((1 == value_) ? true : false);
	}

	void BinReader::runInt8(__i8& nValue, const char * nName, const __i8 nOptimal)
	{
		mStream.read((char *)(&nValue), sizeof(__i8));
	}

	void BinReader::runInt8s(list<__i8>& nValue, const char * nNames, const char * nName)
	{
		__i16 count_ = 0; __i8 value_ = 0;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runInt8(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runInt8Count(__i8& nValue, const char * nName, const __i32 nCount, const __i8 nOptimal)
	{
		this->runInt8(nValue, nName);
	}

	void BinReader::runInt8sCount(list<__i8>& nValue, const char * nName, const __i32 nCount)
	{
		__i16 count_ = 0; __i8 value_ = 0;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runInt8(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runInt8Semi(list<__i8>& nValue, const char * nName)
	{
		__i16 count_ = 0; __i8 value_ = 0;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runInt8(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runInt16(__i16& nValue, const char * nName, const __i16 nOptimal)
	{
		mStream.read((char *)(&nValue), sizeof(__i16));
	}

	void BinReader::runInt16s(list<__i16>& nValue, const char * nNames, const char * nName)
	{
		__i16 count_ = 0; __i16 value_ = 0;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runInt16(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runInt16Count(__i16& nValue, const char * nName, const __i32 nCount, const __i16 nOptimal)
	{
		this->runInt16(nValue, nName);
	}

	void BinReader::runInt16sCount(list<__i16>& nValue, const char * nName, const __i32 nCount)
	{
		__i16 count_ = 0; __i16 value_ = 0;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runInt16(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runInt16Semi(list<__i16>& nValue, const char * nName)
	{
		__i16 count_ = 0; __i16 value_ = 0;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runInt16(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runInt32(__i32& nValue, const char * nName, const __i32 nOptimal)
	{
		mStream.read((char *)(&nValue), sizeof(__i32));
	}

	void BinReader::runInt32s(list<__i32>& nValue, const char * nNames, const char * nName)
	{
		__i16 count_ = 0; __i32 value_ = 0;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runInt32(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runInt32Count(__i32& nValue, const char * nName, const __i32 nCount, const __i32 nOptimal)
	{
		this->runInt32(nValue, nName);
	}

	void BinReader::runInt32sCount(list<__i32>& nValue, const char * nName, const __i32 nCount)
	{
		__i16 count_ = 0; __i32 value_ = 0;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runInt32(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runInt32Semi(list<__i32>& nValue, const char * nName)
	{
		__i16 count_ = 0; __i32 value_ = 0;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runInt32(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runCrc32(__i32& nValue, const char * nName, const __i32 nOptimal)
	{
		this->runInt32(nValue, nName);
	}

	void BinReader::runCrc32s(list<__i32>& nValue, const char * nNames, const char * nName)
	{
		__i16 count_ = 0; __i32 value_ = 0;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runInt32(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runCrc32Count(__i32& nValue, const char * nName, const __i32 nCount, const __i32 nOptimal)
	{
		this->runInt32(nValue, nName);
	}

	void BinReader::runCrc32sCount(list<__i32>& nValue, const char * nName, const __i32 nCount)
	{
		__i16 count_ = 0; __i32 value_ = 0;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runInt32(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runCrc32Semi(list<__i32>& nValue, const char * nName)
	{
		__i16 count_ = 0; __i32 value_ = 0;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runInt32(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runInt64(__i64& nValue, const char * nName, const __i64 nOptimal)
	{
		mStream.read((char *)(&nValue), sizeof(__i64));
	}

	void BinReader::runInt64s(list<__i64>& nValue, const char * nNames, const char * nName)
	{
		__i16 count_ = 0; __i64 value_ = 0;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runInt64(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runInt64Count(__i64& nValue, const char * nName, const __i32 nCount, const __i64 nOptimal)
	{
		this->runInt64(nValue, nName);
	}

	void BinReader::runInt64sCount(list<__i64>& nValue, const char * nName, const __i32 nCount)
	{
		__i16 count_ = 0; __i64 value_ = 0;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runInt64(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runInt64Semi(list<__i64>& nValue, const char * nName)
	{
		__i16 count_ = 0; __i64 value_ = 0;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runInt64(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runString(string& nValue, const char * nName, const char * nOptimal)
	{
		__i16 count_ = 0;
		this->runInt16(count_, "count");
		nValue.resize(count_);
		mStream.read((char *)(&nValue[0]), sizeof(char)* count_);
	}

	void BinReader::runStrings(list<string>& nValue, const char * nNames, const char * nName)
	{
		__i16 count_ = 0;
		mStream.read((char *)(&count_), sizeof(__i16));
		for (__i16 i = 0; i < count_; ++i) {
			string str_;
			this->runString(str_, nName);
			nValue.push_back(str_);
		}
	}

	void BinReader::runStringCount(string& nValue, const char * nName, const __i32 nCount, const char * nOptimal)
	{
		__i16 count_ = 0;
		this->runInt16(count_, "count");
		nValue.resize(count_);
		mStream.read((char *)(&nValue[0]), sizeof(char)* count_);
	}

	void BinReader::runStringsCount(list<string>& nValue, const char * nName, const __i32 nCount)
	{
		__i16 count_ = 0;
		this->runInt16(count_, "count");
		for (__i16 i = 0; i < count_; ++i) {
			string str_;
			this->runString(str_, nName);
			nValue.push_back(str_);
		}
	}

	void BinReader::runStringSemi(list<string>& nValue, const char * nName)
	{
		__i16 count_ = 0;
		mStream.read((char *)(&count_), sizeof(__i16));
		for (__i16 i = 0; i < count_; ++i) {
			string str_;
			this->runString(str_, nName);
			nValue.push_back(str_);
		}
	}

	void BinReader::runFloat(float& nValue, const char * nName, const float nOptimal)
	{
		mStream.read((char *)(&nValue), sizeof(float));
	}

	void BinReader::runFloats(list<float>& nValue, const char * nNames, const char * nName)
	{
		__i16 count_ = 0; float value_ = 0.f;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runFloat(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runFloatCount(float& nValue, const char * nName, const __i32 nCount, const float nOptimal)
	{
		mStream.read((char *)(&nValue), sizeof(float));
	}

	void BinReader::runFloatsCount(list<float>& nValue, const char * nName, const __i32 nCount)
	{
		__i16 count_ = 0; float value_ = 0.f;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runFloat(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runFloatSemi(list<float>& nValue, const char * nName)
	{
		__i16 count_ = 0; float value_ = 0.f;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runFloat(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runDouble(double& nValue, const char * nName, const double nOptimal)
	{
		mStream.read((char *)(&nValue), sizeof(double));
	}

	void BinReader::runDoubles(list<double>& nValue, const char * nNames, const char * nName)
	{
		__i16 count_ = 0; double value_ = 0.;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runDouble(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runDoubleCount(double& nValue, const char * nName, const __i32 nCount, const double nOptimal)
	{
		mStream.read((char *)(&nValue), sizeof(double));
	}

	void BinReader::runDoublesCount(list<double>& nValue, const char * nName, const __i32 nCount)
	{
		__i16 count_ = 0; double value_ = 0.;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runDouble(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runDoubleSemi(list<double>& nValue, const char * nName)
	{
		__i16 count_ = 0; double value_ = 0.;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runDouble(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	bool BinReader::openUrl(const char * nUrl)
	{
#ifdef __COCOS2DX__
		if (!FileUtils::getInstance()->isFileExist(nUrl)) {
			return false;
		}
		mStream.open(nUrl, ios::binary | ios::in);
		if (mStream.is_open()) {
			return true;
		}
		return false;
#else
		mStream.open(nUrl, ios::binary | ios::in);
		if (mStream.is_open()) {
			return true;
		}
		return false;
#endif
	}

	void BinReader::selectStream(const char * nStreamName) const
	{
	}

	__i32 BinReader::pushStream(const char * nName)
	{
		return 0;
	}

	void BinReader::popStream()
	{
	}

	void BinReader::runRead(char * nValue, const __i32 nLength)
	{
		mStream.read(nValue, nLength);
	}

	void BinReader::runSeek(const __i32 nPos)
	{
		mStream.seekg(nPos, ios::beg);
	}

	__i32 BinReader::runLength()
	{
		__i32 result_ = 0;
		mStream.seekg(0, ios::end);
		result_ = static_cast<__i32>(mStream.tellg());
		mStream.seekg(0, ios::beg);
		return result_;
	}
	
	void BinReader::runClose()
	{
		if (mStream.is_open()) {
			mStream.close();
		}
	}

	BinReader::BinReader()
	{
	}

	BinReader::~BinReader()
	{
	}

}
