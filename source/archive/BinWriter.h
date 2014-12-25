#pragma once

namespace std {

	class __funapi BinWriter : noncopyable
	{
	public:
		void runBool(bool& nValue, const char * nName, const bool nOptimal = false);

		void runInt8(__i8& nValue, const char * nName, const __i8 nOptimal = 0);
		void runInt8s(list<__i8>& nValue, const char * nNames, const char * nName);
		void runInt8Count(__i8& nValue, const char * nName, const __i32 nCount, const __i8 nOptimal = 0);
		void runInt8sCount(list<__i8>& nValue, const char * nName, const __i32 nCount);
		void runInt8Semi(list<__i8>& nValue, const char * nName);

		void runInt16(__i16& nValue, const char * nName, const __i16 nOptimal = 0);
		void runInt16s(list<__i16>& nValue, const char * nNames, const char * nName);
		void runInt16Count(__i16& nValue, const char * nName, const __i32 nCount, const __i16 nOptimal = 0);
		void runInt16sCount(list<__i16>& nValue, const char * nName, const __i32 nCount);
		void runInt16Semi(list<__i16>& nValue, const char * nName);

		void runInt32(__i32& nValue, const char * nName, const __i32 nOptimal = 0);
		void runInt32s(list<__i32>& nValue, const char * nNames, const char * nName);
		void runInt32Count(__i32& nValue, const char * nName, const __i32 nCount, const __i32 nOptimal = 0);
		void runInt32sCount(list<__i32>& nValue, const char * nName, const __i32 nCount);
		void runInt32Semi(list<__i32>& nValue, const char * nName);

		void runCrc32(__i32& nValue, const char * nName, const __i32 nOptimal = 0);
		void runCrc32s(list<__i32>& nValue, const char * nNames, const char * nName);
		void runCrc32Count(__i32& nValue, const char * nName, const __i32 nCount, const __i32 nOptimal = 0);
		void runCrc32sCount(list<__i32>& nValue, const char * nName, const __i32 nCount);
		void runCrc32Semi(list<__i32>& nValue, const char * nName);

		void runInt64(__i64& nValue, const char * nName, const __i64 nOptimal = 0);
		void runInt64s(list<__i64>& nValue, const char * nNames, const char * nName);
		void runInt64Count(__i64& nValue, const char * nName, const __i32 nCount, const __i64 nOptimal = 0);
		void runInt64sCount(list<__i64>& nValue, const char * nName, const __i32 nCount);
		void runInt64Semi(list<__i64>& nValue, const char * nName);

		void runString(string& nValue, const char * nName, const char * nOptimal = "");
		void runStrings(list<string>& nValue, const char * nNames, const char * nName);
		void runStringCount(string& nValue, const char * nName, const __i32 nCount, const char * nOptimal = "");
		void runStringsCount(list<string>& nValue, const char * nName, const __i32 nCount);
		void runStringSemi(list<string>& nValue, const char * nName);

		void runFloat(float& nValue, const char * nName, const float nOptimal = 0.f);
		void runFloats(list<float>& nValue, const char * nNames, const char * nName);
		void runFloatCount(float& nValue, const char * nName, const __i32 nCount, const float nOptimal = 0.f);
		void runFloatsCount(list<float>& nValue, const char * nName, const __i32 nCount);
		void runFloatSemi(list<float>& nValue, const char * nName);

		void runDouble(double& nValue, const char * nName, const double nOptimal = 0.);
		void runDoubles(list<double>& nValue, const char * nNames, const char * nName);
		void runDoubleCount(double& nValue, const char * nName, const __i32 nCount, const double nOptimal = 0.);
		void runDoublesCount(list<double>& nValue, const char * nName, const __i32 nCount);
		void runDoubleSemi(list<double>& nValue, const char * nName);

		template<class T>
		void runStream(T& nValue, const char * nName)
		{
			nValue.serialize(this, 0);
		}
		
		template<class T>
		void runStreamCount(T& nValue, const char * nName, const __i32 nCount = 0)
		{
			nValue.serialize(this, nCount);
		}
		
		template<class T>
		void runStreamsCount(list<shared_ptr<T>>& nValue, const char * nNames, const char * nName, const __i32 nCount = 0)
		{
			__i16 count_ = static_cast<__i16>(nValue.size());
			this->runInt16(count_, "count");
			typename list<shared_ptr<T0>>::iterator it = nValue.begin();
			for (; it != nValue.end(); ++it) {
				shared_ptr<T0>& t_ = (*it);
				t_->serialize(this, count_);
			}
		}
		
		template<class T0, class T1>
		void runKeyStreamsCount(map<T0, shared_ptr<T1>>& nValue, const char * nNames, const char * nName, const __i32 nCount = 0)
		{
			__i16 count_ = static_cast<__i16>(nValue.size());
			this->runInt16(count_, "count");
			typename map<T0, shared_ptr<T1>>::iterator it = nValue.begin();
			for (; it != nValue.end(); ++it) {
				shared_ptr<T1>& t_ = it->second;
				t_->serialize(this, count_);
			}
		}
		
		bool openUrl(const char * nUrl);
		void selectStream(const char * nStreamName) const;
		__i32 pushStream(const char * nName);
		void popStream();
		void runWrite(char * nValue, const __i32 nLength);
		void runSeek(const __i32 nPos);
		__i32 runTell();
		void runClose();

	public:
		BinWriter();
		~BinWriter();

	private:
		fstream mStream;
	};
	
}
