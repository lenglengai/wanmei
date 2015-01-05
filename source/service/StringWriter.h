#pragma once

namespace std {
	
	class StringWriter : noncopyable
	{
	public:
		void runBool(const bool nValue, const char * nName);

		void runInt8(const __i8 nValue, const char * nName);
		void runInt8s(const list<__i8>& nValue, const char * nName);
		void runInt8s(const vector<__i8>& nValue, const char * nName);

		void runInt16(const __i16 nValue, const char * nName);
		void runInt16s(const list<__i16>& nValue, const char * nName);
		void runInt16s(const vector<__i16>& nValue, const char * nName);

		void runInt32(const __i32 nValue, const char * nName);
		void runInt32s(const list<__i32>& nValue, const char * nName);
		void runInt32s(const vector<__i32>& nValue, const char * nName);

		void runInt64(const __i64 nValue, const char * nName);
		void runInt64s(const list<__i64>& nValue, const char * nName);
		void runInt64s(const vector<__i64>& nValue, const char * nName);

		void runString(const string& nValue, const char * nName);
		void runString(const char * nValue, const char * nName);
		void runStrings(const list<string>& nValue, const char * nName);
		void runStrings(const vector<string>& nValue, const char * nName);
		
		void runFloat(const float nValue, const char * nName);
		void runFloats(const list<float>& nValue, const char * nName);
		void runFloats(const vector<float>& nValue, const char * nName);
		
		void runDouble(const double nValue, const char * nName);
		void runDoubles(const list<double>& nValue, const char * nName);
		void runDoubles(const vector<double>& nValue, const char * nName);
		
		template<class __t>
		void runStream(const shared_ptr<__t>& nValue, const char * nName)
		{
			this->startClass(nName);
			nValue->runStringWriter(this);
			this->finishClass();
		}
	
		template<class __t>
		void runStreams(const list<shared_ptr<__t>>& nValue, const char * nName)
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
				this->startClass();
				i->runStringWriter(this);
				this->finishClass();
			}
			mValue += "]";
		}
		
		template<class __t0, class __t1>
		void runKeyStream(const map<__t0, shared_ptr<__t1>>& nValue, const char * nName)
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
				this->startClass();
				const shared_ptr<__t1>& t_ = i.second;
				t_->runStringWriter(this);
				this->finishClass();
			}
			mValue += "]";
		}
		
		void startClass(const char * nClassName);
		void startClass();
		void finishClass();
		
		const char * getValue() const;
		void runClose();
		void runClear();
		
		StringWriter();
		~StringWriter();
		
	private:
		string mValue;
		string mSpace;
		bool mFirst;
	};
	typedef shared_ptr<StringWriter> StringWriterPtr;
	
}
