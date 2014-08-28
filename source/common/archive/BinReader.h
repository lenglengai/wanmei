#pragma once

#include <fstream>

#ifdef __ARCHIVE__
namespace std {

	class __funapi BinReader : boost::noncopyable
	{
	public:
		void runBool(bool& nValue, const char * nName, bool nOptimal = false);

		void runInt8(__i8& nValue, const char * nName, __i8 nOptimal = 0);
		void runInt8s(list<__i8>& nValue, const char * nNames, const char * nName);
		void runInt8Count(__i8& nValue, const char * nName, __i32 nCount, __i8 nOptimal = 0);
		void runInt8sCount(list<__i8>& nValue, const char * nName, __i32 nCount);
		void runInt8Semi(list<__i8>& nValue, const char * nName);

		void runInt16(__i16& nValue, const char * nName, __i16 nOptimal = 0);
		void runInt16s(list<__i16>& nValue, const char * nNames, const char * nName);
		void runInt16Count(__i16& nValue, const char * nName, __i32 nCount, __i16 nOptimal = 0);
		void runInt16sCount(list<__i16>& nValue, const char * nName, __i32 nCount);
		void runInt16Semi(list<__i16>& nValue, const char * nName);

		void runInt32(__i32& nValue, const char * nName, __i32 nOptimal = 0);
		void runInt32s(list<__i32>& nValue, const char * nNames, const char * nName);
		void runInt32Count(__i32& nValue, const char * nName, __i32 nCount, __i32 nOptimal = 0);
		void runInt32sCount(list<__i32>& nValue, const char * nName, __i32 nCount);
		void runInt32Semi(list<__i32>& nValue, const char * nName);

		void runCrc32(__i32& nValue, const char * nName, __i32 nOptimal = 0);
		void runCrc32s(list<__i32>& nValue, const char * nNames, const char * nName);
		void runCrc32Count(__i32& nValue, const char * nName, __i32 nCount, __i32 nOptimal = 0);
		void runCrc32sCount(list<__i32>& nValue, const char * nName, __i32 nCount);
		void runCrc32Semi(list<__i32>& nValue, const char * nName);

		void runInt64(__i64& nValue, const char * nName, __i64 nOptimal = 0);
		void runInt64s(list<__i64>& nValue, const char * nNames, const char * nName);
		void runInt64Count(__i64& nValue, const char * nName, __i32 nCount, __i64 nOptimal = 0);
		void runInt64sCount(list<__i64>& nValue, const char * nName, __i32 nCount);
		void runInt64Semi(list<__i64>& nValue, const char * nName);

		void runString(string& nValue, const char * nName, const char * nOptimal = "");
		void runStrings(list<string>& nValue, const char * nNames, const char * nName);
		void runStringCount(string& nValue, const char * nName, __i32 nCount, const char * nOptimal = "");
		void runStringsCount(list<string>& nValue, const char * nName, __i32 nCount);
		void runStringSemi(list<string>& nValue, const char * nName);

		void runFloat(float& nValue, const char * nName, float nOptimal = 0.f);
		void runFloats(list<float>& nValue, const char * nNames, const char * nName);
		void runFloatCount(float& nValue, const char * nName, __i32 nCount, float nOptimal = 0.f);
		void runFloatsCount(list<float>& nValue, const char * nName, __i32 nCount);
		void runFloatSemi(list<float>& nValue, const char * nName);

		void runDouble(double& nValue, const char * nName, double nOptimal = 0.);
		void runDoubles(list<double>& nValue, const char * nNames, const char * nName);
		void runDoubleCount(double& nValue, const char * nName, __i32 nCount, double nOptimal = 0.);
		void runDoublesCount(list<double>& nValue, const char * nName, __i32 nCount);
		void runDoubleSemi(list<double>& nValue, const char * nName);

		template<class T>
		void runStream(T& nValue, const char * nName);
		template<class T>
		void runStreamCount(T& nValue, const char * nName, __i32 nCount = 0);
		template<class T>
		void runStreamsCount(list<std::shared_ptr<T>>& nValue, const char * nNames, const char * nName, __i32 nCount = 0);
		template<class T0, class T1>
		void runKeyStreamsCount(map<T0, std::shared_ptr<T1>>& nValue, const char * nNames, const char * nName, __i32 nCount = 0);

		bool openUrl(const char * nUrl);
		void selectStream(const char * nStreamName);
		__i32 pushStream(const char * nName);
		void popStream();
		void runRead(char * nValue, __i32 nLength);
		void runSeek(__i32 nPos);
		__i32 runLength();
		void runClose();

		BinReader();
		~BinReader();

	private:
		fstream mStream;
	};

	template<class T>
	void BinReader::runStream(T& nValue, const char * nName)
	{
		nValue.serialize(this, 0);
	}

	template<class T>
	void BinReader::runStreamCount(T& nValue, const char * nName, __i32 nCount)
	{
		nValue.serialize(this, nCount);
	}

	template<class T0>
	void BinReader::runStreamsCount(list<std::shared_ptr<T0> >& nValue, const char * nNames, const char * nName, __i32 nCount)
	{
		__i16 count_ = 0; __i8 value_ = 0;
		this->runInt16(count_, "count");
		for (__i16 i = 0; i < count_; ++i) {
			std::shared_ptr<T0> t_(new T0());
			t_->serialize(this, nCount);
			nValue.push_back(t_);
		}
	}

	template<class T0, class T1>
	void BinReader::runKeyStreamsCount(map<T0, std::shared_ptr<T1>>& nValue, const char * nNames, const char * nName, __i32 nCount)
	{
		__i16 count_ = 0; __i8 value_ = 0;
		this->runInt16(count_, "count");
		for (__i16 i = 0; i < count_; ++i) {
			std::shared_ptr<T1> t_(new T1());
			t_->serialize(this, nCount);
			nValue[t_->getKey()] = t_;
		}
	}
}
#endif
