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
		mValue += __convert<bool, string>(nValue, ConvertType_::mText_);
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
		mValue += __convert<__i8, string>(nValue);
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
			mValue += __convert<__i8, string>(i);
		}
		mValue += "]";
	}
	
	void StringWriter::runInt8s(const vector<__i8>& nValue, const char * nName)
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
			mValue += __convert<__i8, string>(i);
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
		mValue += __convert<__i16, string>(nValue);
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
			mValue += __convert<__i16, string>(i);
		}
		mValue += "]";
	}
	
	void StringWriter::runInt16s(const vector<__i16>& nValue, const char * nName)
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
			mValue += __convert<__i16, string>(i);
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
		mValue += __convert<__i32, string>(nValue);
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
			mValue += __convert<__i32, string>(i);
		}
		mValue += "]";
	}
	
	void StringWriter::runInt32s(const vector<__i32>& nValue, const char * nName)
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
			mValue += __convert<__i32, string>(i);
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
		mValue += __convert<__i64, string>(nValue);
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
			mValue += __convert<__i64, string>(i);
		}
		mValue += "]";
	}
	
	void StringWriter::runInt64s(const vector<__i64>& nValue, const char * nName)
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
			mValue += __convert<__i64, string>(i);
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
			mValue += i;
			mValue += "\"";
		}
		mValue += "]";
	}
	
	void StringWriter::runStrings(const vector<string>& nValue, const char * nName)
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
			mValue += i;
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
		mValue += __convert<float, string>(nValue);
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
			mValue += __convert<float, string>(i);
		}
		mValue += "]";
	}
	
	void StringWriter::runFloats(const vector<float>& nValue, const char * nName)
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
			mValue += __convert<float, string>(i);
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
		mValue += __convert<double, string>(nValue);
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
			mValue += __convert<double, string>(i);
		}
		mValue += "]";
	}
	
	void StringWriter::runDoubles(const vector<double>& nValue, const char * nName)
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
			mValue += __convert<double, string>(i);
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
	
	void StringWriter::startClass()
	{
		if ( !mFirst ) {
			mValue += ",";
		} else {
			mFirst = false;
		}
		mValue += "{";
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
