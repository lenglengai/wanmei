#pragma once

#ifdef __WITHSQL__
namespace std {

	class IDbQuery : noncopyable
	{
	public:
		virtual void runBool(bool& nValue) = 0;
		virtual void runInt8(__i8& nValue) = 0;
		virtual void runInt16(__i16& nValue) = 0;
		virtual void runInt32(__i32& nValue) = 0;
		virtual void runInt64(__i64& nValue) = 0;
		virtual void runFloat(float& nValue) = 0;
		virtual void runDouble(double& nValue) = 0;
		virtual void runString(string& nValue) = 0;
		virtual void runData(char *& nValue, __i16& nSize) = 0;
		virtual bool nextRow() = 0;
	};
	
}
#endif
