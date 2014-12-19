#pragma once

namespace std {
	
	class StringWriter : noncopyable
	{
	public:
		void runBool(const bool nValue, const char * nName);

		void runInt8(const __i8 nValue, const char * nName);
		void runInt8s(const list<__i8>& nValue, const char * nName);

		void runInt16(const __i16 nValue, const char * nName);
		void runInt16s(const list<__i16>& nValue, const char * nName);

		void runInt32(const __i32 nValue, const char * nName);
		void runInt32s(const list<__i32>& nValue, const char * nName);

		void runInt64(const __i64 nValue, const char * nName);
		void runInt64s(const list<__i64>& nValue, const char * nName);

		void runString(const string& nValue, const char * nName);
		void runString(const char * nValue, const char * nName);
		void runStrings(const list<string>& nValue, const char * nName);

		void runFloat(const float nValue, const char * nName);
		void runFloats(const list<float>& nValue, const char * nName);

		void runDouble(const double nValue, const char * nName);
		void runDoubles(list<double>& nValue, const char * nName);
		
		void startClass(const char * nClassName);
		void finishClass();
		
		const char * getValue();
		
		StringWriter();
		~StringWriter();
		
	private:
		string mValue;
		bool mFirst;
	};
	typedef shared_ptr<StringWriter> StringWriterPtr;
	
}
