#include "../Include.h"

namespace std {

	void StringWriter::runBool(bool& nValue, const char * nName)
	{
		if ( !mFirst ) {
			mValue += ",\"";
		} else {
			mValue += "\"";
			mFirst = false;
		}
		mValue += nName; mValue += "\":";
		mValue += __convert<string, bool>(nValue, mConvertTypeText_);
	}
	
	void StringWriter::runInt8(__i8& nValue, const char * nName)
	{
		if ( !mFirst ) {
			mValue += ",\"";
		} else {
			mValue += "\"";
			mFirst = false;
		}
		mValue += nName; mValue += "\":";
		mValue += __convert<string, __i8>(nValue);
	}
	
	void StringWriter::runInt8s(list<__i8>& nValue, const char * nName)
	{
		if ( !mFirst ) {
			mValue += ",\"";
		} else {
			mValue += "\"";
		}
		mValue += nName; mValue += "\":[";
		mFirst = true;
		for (auto& i : nValue) {
			if ( !mFirst ) {
				mValue += ",";
			} else {
				mFirst = false;
			}
			mValue += __convert<string, __i8>(nValue);
		}
		mValue += "]";
	}
	
	void StringWriter::runInt16(__i16& nValue, const char * nName)
	{
		if ( !mFirst ) {
			mValue += ",\"";
		} else {
			mValue += "\"";
			mFirst = false;
		}
		mValue += nName; mValue += "\":";
		mValue += __convert<string, __i16>(nValue);
	}
	
	void StringWriter::runInt16s(list<__i16>& nValue, const char * nName)
	{
		if ( !mFirst ) {
			mValue += ",\"";
		} else {
			mValue += "\"";
		}
		mValue += nName; mValue += "\":[";
		mFirst = true;
		for (auto& i : nValue) {
			if ( !mFirst ) {
				mValue += ",";
			} else {
				mFirst = false;
			}
			mValue += __convert<string, __i16>(nValue);
		}
		mValue += "]";
	}
	
	void StringWriter::runInt32(__i32& nValue, const char * nName)
	{
		if ( !mFirst ) {
			mValue += ",\"";
		} else {
			mValue += "\"";
			mFirst = false;
		}
		mValue += nName; mValue += "\":";
		mValue += __convert<string, __i32>(nValue);
	}
	
	void StringWriter::runInt32s(list<__i32>& nValue, const char * nName)
	{
		if ( !mFirst ) {
			mValue += ",\"";
		} else {
			mValue += "\"";
		}
		mValue += nName; mValue += "\":[";
		mFirst = true;
		for (auto& i : nValue) {
			if ( !mFirst ) {
				mValue += ",";
			} else {
				mFirst = false;
			}
			mValue += __convert<string, __i32>(nValue);
		}
		mValue += "]";
	}
	
	void StringWriter::runInt64(__i64& nValue, const char * nName)
	{
		if ( !mFirst ) {
			mValue += ",\"";
		} else {
			mValue += "\"";
			mFirst = false;
		}
		mValue += nName; mValue += "\":";
		mValue += __convert<string, __i64>(nValue);
	}
	
	void StringWriter::runInt64s(list<__i64>& nValue, const char * nName)
	{
		if ( !mFirst ) {
			mValue += ",\"";
		} else {
			mValue += "\"";
		}
		mValue += nName; mValue += "\":[";
		mFirst = true;
		for (auto& i : nValue) {
			if ( !mFirst ) {
				mValue += ",";
			} else {
				mFirst = false;
			}
			mValue += __convert<string, __i64>(nValue);
		}
		mValue += "]";
	}
	
	void StringWriter::runString(string& nValue, const char * nName)
	{
		if ( !mFirst ) {
			mValue += ",\"";
		} else {
			mValue += "\"";
			mFirst = false;
		}
		mValue += nName; 
		mValue += "\":\"";
		mValue += nValue;
		mValue += "\"";
	}
	
	void StringWriter::runString(const char * nValue, const char * nName)
	{
		if ( !mFirst ) {
			mValue += ",\"";
		} else {
			mValue += "\"";
			mFirst = false;
		}
		mValue += nName; 
		mValue += "\":\"";
		mValue += nValue;
		mValue += "\"";
	}
	
	void StringWriter::runStrings(list<string>& nValue, const char * nName)
	{
		if ( !mFirst ) {
			mValue += ",\"";
		} else {
			mValue += "\"";
		}
		mValue += nName; mValue += "\":[";
		mFirst = true;
		for (auto& i : nValue) {
			if ( !mFirst ) {
				mValue += ",\"";
			} else {
				mValue += "\"";
				mFirst = false;
			}
			mValue += __convert<string, __i64>(nValue);
			mValue += "\"";
		}
		mValue += "]";
	}
	
	void StringWriter::runFloat(float& nValue, const char * nName)
	{
		if ( !mFirst ) {
			mValue += ",\"";
		} else {
			mValue += "\"";
			mFirst = false;
		}
		mValue += nName; mValue += "\":";
		mValue += __convert<string, float>(nValue);
	}
	
	void StringWriter::runFloats(list<float>& nValue, const char * nName)
	{
		if ( !mFirst ) {
			mValue += ",\"";
		} else {
			mValue += "\"";
		}
		mValue += nName; mValue += "\":[";
		mFirst = true;
		for (auto& i : nValue) {
			if ( !mFirst ) {
				mValue += ",";
			} else {
				mFirst = false;
			}
			mValue += __convert<string, float>(nValue);
		}
		mValue += "]";
	}
	
	void StringWriter::runDouble(double& nValue, const char * nName)
	{
		if ( !mFirst ) {
			mValue += ",\"";
		} else {
			mValue += "\"";
			mFirst = false;
		}
		mValue += nName; mValue += "\":";
		mValue += __convert<string, double>(nValue);
	}
	
	void StringWriter::runDoubles(list<double>& nValue, const char * nName)
	{
		if ( !mFirst ) {
			mValue += ",\"";
		} else {
			mValue += "\"";
		}
		mValue += nName; mValue += "\":[";
		mFirst = true;
		for (auto& i : nValue) {
			if ( !mFirst ) {
				mValue += ",";
			} else {
				mFirst = false;
			}
			mValue += __convert<string, double>(nValue);
		}
		mValue += "]";
	}
	
	void StringWriter::startClass(const char * nClassName)
	{
		if ( !mFirst ) {
			mValue += ",\"";
		} else {
			mValue += "\"";
			mFirst = false;
		}
		mValue += nClassName;
		mValue += "\":{";
	}
	
	void StringWriter::finishClass()
	{
		mValue += "}";
	}
	
	const char * StringWriter::getValue()
	{
		return mValue.c_str();
	}
	
	StringWriter::StringWriter()
		: mValue("")
	{
		mFirst = true;
	}
	
	StringWriter::~StringWriter()
	{
		mFirst = true;
		mValue = "";
	}

}
