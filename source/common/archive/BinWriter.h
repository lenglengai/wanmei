#pragma once

#include <fstream>

namespace std {

	class __funapi BinWriter : boost::noncopyable
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
		void runWrite(char * nValue, __i32 nLength);
		void runSeek(__i32 nPos);
		__i32 runTell();
		void runClose();

	public:
		BinWriter();
		~BinWriter();

	private:
		fstream mStream;
	};

	template<class T>
	void BinWriter::runStream(T& nValue, const char * nName)
	{
		nValue.serialize(this, 0);
	}

	template<class T>
	void BinWriter::runStreamCount(T& nValue, const char * nName, __i32 nCount)
	{
		nValue.serialize(this, nCount);
	}

	template<class T0>
	void BinWriter::runStreamsCount(list<std::shared_ptr<T0> >& nValue, const char * nNames, const char * nName, __i32 nCount)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		std::list<shared_ptr<T0>>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			std::shared_ptr<T0>& t_ = (*it);
			t_->serialize(this, count_);
		}
	}

	template<class T0, class T1>
	void BinWriter::runKeyStreamsCount(map<T0, std::shared_ptr<T1>>& nValue, const char * nNames, const char * nName, __i32 nCount)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		map<T0, std::shared_ptr<T1>>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			std::shared_ptr<T1>& t_ = it->second;
			t_->serialize(this, count_);
		}
	}
}