#pragma once

namespace std {

	class __funapi LogWriter : boost::noncopyable
	{
	public:
		void runBool(bool& nValue, const char * nName, bool nOptimal = false);

		void runInt8(__i8& nValue, const char * nName, __i8 nOptimal = 0);
		void runInt8s(std::list<__i8>& nValue, const char * nNames, const char * nName);
		void runInt8Count(__i8& nValue, const char * nName, __i32 nCount, __i8 nOptimal = 0);
		void runInt8sCount(std::list<__i8>& nValue, const char * nName, __i32 nCount);
		void runInt8Semi(std::list<__i8>& nValue, const char * nName);

		void runInt16(__i16& nValue, const char * nName, __i16 nOptimal = 0);
		void runInt16s(std::list<__i16>& nValue, const char * nNames, const char * nName);
		void runInt16Count(__i16& nValue, const char * nName, __i32 nCount, __i16 nOptimal = 0);
		void runInt16sCount(std::list<__i16>& nValue, const char * nName, __i32 nCount);
		void runInt16Semi(std::list<__i16>& nValue, const char * nName);

		void runInt32(__i32& nValue, const char * nName, __i32 nOptimal = 0);
		void runInt32s(std::list<__i32>& nValue, const char * nNames, const char * nName);
		void runInt32Count(__i32& nValue, const char * nName, __i32 nCount, __i32 nOptimal = 0);
		void runInt32sCount(std::list<__i32>& nValue, const char * nName, __i32 nCount);
		void runInt32Semi(std::list<__i32>& nValue, const char * nName);

		void runCrc32(__i32& nValue, const char * nName, __i32 nOptimal = 0);
		void runCrc32s(std::list<__i32>& nValue, const char * nNames, const char * nName);
		void runCrc32Count(__i32& nValue, const char * nName, __i32 nCount, __i32 nOptimal = 0);
		void runCrc32sCount(std::list<__i32>& nValue, const char * nName, __i32 nCount);
		void runCrc32Semi(std::list<__i32>& nValue, const char * nName);

		void runInt64(__i64& nValue, const char * nName, __i64 nOptimal = 0);
		void runInt64s(std::list<__i64>& nValue, const char * nNames, const char * nName);
		void runInt64Count(__i64& nValue, const char * nName, __i32 nCount, __i64 nOptimal = 0);
		void runInt64sCount(std::list<__i64>& nValue, const char * nName, __i32 nCount);
		void runInt64Semi(std::list<__i64>& nValue, const char * nName);

		void runString(std::string& nValue, const char * nName, const char * nOptimal = "");
		void runStrings(std::list<std::string>& nValue, const char * nNames, const char * nName);
		void runStringCount(std::string& nValue, const char * nName, __i32 nCount, const char * nOptimal = "");
		void runStringsCount(std::list<string>& nValue, const char * nName, __i32 nCount);
		void runStringSemi(std::list<std::string>& nValue, const char * nName);

		void runFloat(float& nValue, const char * nName, float nOptimal = 0.f);
		void runFloats(std::list<float>& nValue, const char * nNames, const char * nName);
		void runFloatCount(float& nValue, const char * nName, __i32 nCount, float nOptimal = 0.f);
		void runFloatsCount(std::list<float>& nValue, const char * nName, __i32 nCount);
		void runFloatSemi(std::list<float>& nValue, const char * nName);

		void runDouble(double& nValue, const char * nName, double nOptimal = 0.);
		void runDoubles(std::list<double>& nValue, const char * nNames, const char * nName);
		void runDoubleCount(double& nValue, const char * nName, __i32 nCount, double nOptimal = 0.);
		void runDoublesCount(std::list<double>& nValue, const char * nName, __i32 nCount);
		void runDoubleSemi(std::list<double>& nValue, const char * nName);

		template<class T>
		void runStream(T& nValue, const char * nName);
		template<class T>
		void runStreamCount(T& nValue, const char * nName, __i32 nCount = 0);
		template<class T>
		void runStreamsCount(std::list<std::shared_ptr<T>>& nValue, const char * nNames, const char * nName, __i32 nCount = 0);
		template<class T0, class T1>
		void runKeyStreamsCount(std::map<T0, std::shared_ptr<T1>>& nValue, const char * nNames, const char * nName, __i32 nCount = 0);

		bool openUrl(const char * nUrl);
		void selectStream(const char * nStreamName);
		__i32 pushStream(const char * nName);
		void popStream();
		void runClose();

	public:
		LogWriter();
		~LogWriter();
	
	private:
		std::string mValue;
	};

	template<class T>
	void LogWriter::runStream(T& nValue, const char * nName)
	{
		nValue.serialize(this, 0);
	}

	template<class T>
	void LogWriter::runStreamCount(T& nValue, const char * nName, __i32 nCount)
	{
		nValue.serialize(this, nCount);
	}

	template<class T0>
	void LogWriter::runStreamsCount(std::list<std::shared_ptr<T0> >& nValue, const char * nNames, const char * nName, __i32 nCount)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		typename std::list<std::shared_ptr<T0>>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			std::shared_ptr<T0>& t_ = (*it);
			t_->serialize(this, count_);
		}
	}

	template<class T0, class T1>
	void LogWriter::runKeyStreamsCount(std::map<T0, std::shared_ptr<T1>>& nValue, const char * nNames, const char * nName, __i32 nCount)
	{
		__i16 count_ = static_cast<__i16>(nValue.size());
		this->runInt16(count_, "count");
		typename std::map<T0, std::shared_ptr<T1>>::iterator it = nValue.begin();
		for (; it != nValue.end(); ++it) {
			std::shared_ptr<T1>& t_ = it->second;
			t_->serialize(this, count_);
		}
	}
}
