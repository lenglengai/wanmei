#include "../DefInc.h"
#include "BinReader.h"
#include "../setting/SettingService.h"

#ifdef __COCOS2DX__
#include <cocos2d.h>
#endif

#ifdef __ARCHIVE__
namespace std {

	void BinReader::runBool(bool& nValue, const char * nName, bool nOptimal)
	{
		__i8 value_ = 0;
		this->runInt8(value_, nName, nOptimal);
		nValue = ((1 == value_) ? true : false);
	}

	void BinReader::runInt8(__i8& nValue, const char * nName, __i8 nOptimal)
	{
		mStream.read((char *)(&nValue), sizeof(__i8));
	}

	void BinReader::runInt8s(std::list<__i8>& nValue, const char * nNames, const char * nName)
	{
		__i16 count_ = 0; __i8 value_ = 0;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runInt8(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runInt8Count(__i8& nValue, const char * nName, __i32 nCount, __i8 nOptimal)
	{
		this->runInt8(nValue, nName);
	}

	void BinReader::runInt8sCount(std::list<__i8>& nValue, const char * nName, __i32 nCount)
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

	void BinReader::runInt16(__i16& nValue, const char * nName, __i16 nOptimal)
	{
		mStream.read((char *)(&nValue), sizeof(__i16));
	}

	void BinReader::runInt16s(std::list<__i16>& nValue, const char * nNames, const char * nName)
	{
		__i16 count_ = 0; __i16 value_ = 0;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runInt16(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runInt16Count(__i16& nValue, const char * nName, __i32 nCount, __i16 nOptimal)
	{
		this->runInt16(nValue, nName);
	}

	void BinReader::runInt16sCount(std::list<__i16>& nValue, const char * nName, __i32 nCount)
	{
		__i16 count_ = 0; __i16 value_ = 0;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runInt16(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runInt16Semi(std::list<__i16>& nValue, const char * nName)
	{
		__i16 count_ = 0; __i16 value_ = 0;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runInt16(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runInt32(__i32& nValue, const char * nName, __i32 nOptimal)
	{
		mStream.read((char *)(&nValue), sizeof(__i32));
	}

	void BinReader::runInt32s(std::list<__i32>& nValue, const char * nNames, const char * nName)
	{
		__i16 count_ = 0; __i32 value_ = 0;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runInt32(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runInt32Count(__i32& nValue, const char * nName, __i32 nCount, __i32 nOptimal)
	{
		this->runInt32(nValue, nName);
	}

	void BinReader::runInt32sCount(std::list<__i32>& nValue, const char * nName, __i32 nCount)
	{
		__i16 count_ = 0; __i32 value_ = 0;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runInt32(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runInt32Semi(std::list<__i32>& nValue, const char * nName)
	{
		__i16 count_ = 0; __i32 value_ = 0;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runInt32(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runCrc32(__i32& nValue, const char * nName, __i32 nOptimal)
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

	void BinReader::runCrc32Count(__i32& nValue, const char * nName, __i32 nCount, __i32 nOptimal)
	{
		this->runInt32(nValue, nName);
	}

	void BinReader::runCrc32sCount(list<__i32>& nValue, const char * nName, __i32 nCount)
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

	void BinReader::runInt64(__i64& nValue, const char * nName, __i64 nOptimal)
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

	void BinReader::runInt64Count(__i64& nValue, const char * nName, __i32 nCount, __i64 nOptimal)
	{
		this->runInt64(nValue, nName);
	}

	void BinReader::runInt64sCount(std::list<__i64>& nValue, const char * nName, __i32 nCount)
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

	void BinReader::runString(std::string& nValue, const char * nName, const char * nOptimal)
	{
		__i16 count_ = 0;
		this->runInt16(count_, "count");
		nValue.resize(count_);
		mStream.read((char *)(&nValue[0]), sizeof(char)* count_);
	}

	void BinReader::runStrings(std::list<std::string>& nValue, const char * nNames, const char * nName)
	{
		__i16 count_ = 0; __i8 value_ = 0;
		mStream.read((char *)(&count_), sizeof(__i16));
		for (__i16 i = 0; i < count_; ++i) {
			std::string str_;
			this->runString(str_, nName);
			nValue.push_back(str_);
		}
	}

	void BinReader::runStringCount(std::string& nValue, const char * nName, __i32 nCount, const char * nOptimal)
	{
		__i16 count_ = 0;
		this->runInt16(count_, "count");
		nValue.resize(count_);
		mStream.read((char *)(&nValue[0]), sizeof(char)* count_);
	}

	void BinReader::runStringsCount(std::list<std::string>& nValue, const char * nName, __i32 nCount)
	{
		__i16 count_ = 0; __i8 value_ = 0;
		this->runInt16(count_, "count");
		for (__i16 i = 0; i < count_; ++i) {
			std::string str_;
			this->runString(str_, nName);
			nValue.push_back(str_);
		}
	}

	void BinReader::runStringSemi(std::list<std::string>& nValue, const char * nName)
	{
		__i16 count_ = 0; __i8 value_ = 0;
		mStream.read((char *)(&count_), sizeof(__i16));
		for (__i16 i = 0; i < count_; ++i) {
			std::string str_;
			this->runString(str_, nName);
			nValue.push_back(str_);
		}
	}

	void BinReader::runFloat(float& nValue, const char * nName, float nOptimal)
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

	void BinReader::runFloatCount(float& nValue, const char * nName, __i32 nCount, float nOptimal)
	{
		mStream.read((char *)(&nValue), sizeof(float));
	}

	void BinReader::runFloatsCount(std::list<float>& nValue, const char * nName, __i32 nCount)
	{
		__i16 count_ = 0; float value_ = 0.f;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runFloat(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runFloatSemi(std::list<float>& nValue, const char * nName)
	{
		__i16 count_ = 0; float value_ = 0.f;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runFloat(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runDouble(double& nValue, const char * nName, double nOptimal)
	{
		mStream.read((char *)(&nValue), sizeof(double));
	}

	void BinReader::runDoubles(std::list<double>& nValue, const char * nNames, const char * nName)
	{
		__i16 count_ = 0; double value_ = 0.;
		this->runInt16(count_, nName);
		for (__i16 i = 0; i < count_; ++i) {
			this->runDouble(value_, nName);
			nValue.push_back(value_);
			value_ = 0;
		}
	}

	void BinReader::runDoubleCount(double& nValue, const char * nName, __i32 nCount, double nOptimal)
	{
		mStream.read((char *)(&nValue), sizeof(double));
	}

	void BinReader::runDoublesCount(std::list<double>& nValue, const char * nName, __i32 nCount)
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
		SettingService& settingService_ = Singleton<SettingService>::instance();
		std::string url_ = settingService_.systemPath();
		if ("" != url_) url_ += "/"; url_ += nUrl;
		mStream.open(url_, ios::binary | ios::in);
		if (mStream.is_open()) {
			return true;
		}
		return false;
#endif
	}

	void BinReader::selectStream(const char * nStreamName)
	{
	}

	__i32 BinReader::pushStream(const char * nName)
	{
		return 0;
	}

	void BinReader::popStream()
	{
	}

	void BinReader::runRead(char * nValue, __i32 nLength)
	{
		mStream.read(nValue, nLength);
	}

	void BinReader::runSeek(__i32 nPos)
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
		mStream.close();
	}

	BinReader::BinReader()
	{
	}

	BinReader::~BinReader()
	{
	}

}
#endif
