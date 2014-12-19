#include "../Include.h"

namespace std {

	void StringWriter::runBool(const bool nValue, const char * nName)
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
	
	void StringWriter::runInt8(const __i8 nValue, const char * nName)
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
	
	void StringWriter::runInt8s(const list<__i8>& nValue, const char * nName)
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
	
	void StringWriter::runInt16(const __i16 nValue, const char * nName)
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
	
	void StringWriter::runInt16s(const list<__i16>& nValue, const char * nName)
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
	
	void StringWriter::runInt32(const __i32 nValue, const char * nName)
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
	
	void StringWriter::runInt32s(const list<__i32>& nValue, const char * nName)
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
	
	void StringWriter::runInt64(const __i64 nValue, const char * nName)
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
	
	void StringWriter::runInt64s(const list<__i64>& nValue, const char * nName)
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
	
	void StringWriter::runString(const string& nValue, const char * nName)
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
	
	void StringWriter::runStrings(const list<string>& nValue, const char * nName)
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
	
	void StringWriter::runFloat(const float nValue, const char * nName)
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
	
	void StringWriter::runFloats(const list<float>& nValue, const char * nName)
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
	
	void StringWriter::runDouble(const double nValue, const char * nName)
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
	
	void StringWriter::runDoubles(const list<double>& nValue, const char * nName)
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
