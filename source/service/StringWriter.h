#pragma once

namespace std {
	
	class StringWriter : noncopyable
	{
	public:
		void runBool(bool& nValue, const char * nName);

		void runInt8(__i8& nValue, const char * nName);
		void runInt8s(list<__i8>& nValue, const char * nName);

		void runInt16(__i16& nValue, const char * nName);
		void runInt16s(list<__i16>& nValue, const char * nName);

		void runInt32(__i32& nValue, const char * nName);
		void runInt32s(list<__i32>& nValue, const char * nName);

		void runInt64(__i64& nValue, const char * nName);
		void runInt64s(list<__i64>& nValue, const char * nName);

		void runString(string& nValue, const char * nName);
		void runString(const char * nValue, const char * nName);
		void runStrings(list<string>& nValue, const char * nName);

		void runFloat(float& nValue, const char * nName);
		void runFloats(list<float>& nValue, const char * nName);

		void runDouble(double& nValue, const char * nName);
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
