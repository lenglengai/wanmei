#pragma once

#ifdef __WITHSQL__
namespace std {

	class SqlCommand : noncopyable
	{
	public:
		void runBool(bool& nValue, const char * nName, __i8 nSqlFieldId = SqlFieldId_::mNone_);
        void runInt8(__i8& nValue, const char * nName, __i8 nSqlFieldId = SqlFieldId_::mNone_);
        void runInt16(__i16& nValue, const char * nName, __i8 nSqlFieldId = SqlFieldId_::mNone_);
        void runInt32(__i32& nValue, const char * nName, __i8 nSqlFieldId = SqlFieldId_::mNone_);
        void runInt64(__i64& nValue, const char * nName, __i8 nSqlFieldId = SqlFieldId_::mNone_);
        void runString(string& nValue, const char * nName, __i8 nSize, __i8 nSqlFieldId = SqlFieldId_::mNone_);
        void runFloat(float& nValue, const char * nName, __i8 nSqlFieldId = SqlFieldId_::mNone_);
        void runDouble(double& nValue, const char * nName, __i8 nSqlFieldId = SqlFieldId_::mNone_);
		void runData(char *& nValue, __i16& nSize, const char * nName, __i8 nSqlFieldId = SqlFieldId_::mNone_);
		
		void runHeadstream(ISqlHeadstream * nSqlStream);
		const std::string& getValue() const;
		void runClear();
		
	private:
		void runCreateDB(ISqlHeadstream * nSqlHeadstream);
		void runDropDB(ISqlHeadstream * nSqlHeadstream);
		void runSetDB(ISqlHeadstream * nSqlHeadstream);
		
		void runCreateTB(ISqlHeadstream * nSqlHeadstream);
		void runDropTB(ISqlHeadstream * nSqlHeadstream);
		
		void runSelect(ISqlHeadstream * nSqlHeadstream);
		void runInsert(ISqlHeadstream * nSqlHeadstream);
		void runReplace(ISqlHeadstream * nSqlHeadstream);
		void runDelete(ISqlHeadstream * nSqlHeadstream);
		void runUpdate(ISqlHeadstream * nSqlHeadstream);
		void runInsertUpdate(ISqlHeadstream * nSqlHeadstream);
		
		void runQuery(ISqlHeadstream * nSqlHeadstream, IDbQuery * nDbQuery);
		
	private:
		void runCreateFD(const char * nValue, const char * nName, __i8 nSqlFieldId);
		void runCreatePy(const char * nName);
		
		void runSelectFD(const char * nName);
		
		template <typename __t>
	    void runWhere(__t& nValue, const char * nName)
		{
			mValue += "WHERE ";
			mValue += mFieldBegin;
            mValue += nName;
			mValue += mFieldEnd;
			mValue += "=";
            mValue += mValueBegin;
            mValue += __convert<__t, string>(nValue);
            mValue += mValueEnd;
            mValue += " ";
        }
		void runWhere(string& nValue, const char * nName);

		template <typename __t>
        void runInsertFD(__t& nValue)
		{
            if (false == mBeg) {
                mValue += ",";
            }
            mValue += mValueBegin;
			mValue += __convert<__t, string>(nValue);
            mValue += mValueEnd;
            if (mBeg) {
                mBeg = false;
            }
        }
        void runInsertFD(string& nValue);
		
		template <typename __t>
		void runUpdateFD(__t& nValue, const char * nName)
		{
            if (false == mBeg) {
                mValue += ",";
            }
            mValue += mFieldBegin;
            mValue += nName;
            mValue += mFieldEnd;
            mValue += "=";
            mValue += mValueBegin;
            mValue += __convert<__t, string>(nValue);
            mValue += mValueEnd;
            if (mBeg) {
                mBeg = false;
            }
        }
		void runUpdateFD(string& nValue, const char * nName);
		
		void runInsertUpdateFD(const char * nName);
		
	private:
		template <typename __t>
		void runType(__t& nValue, const char * nSql, const char * nName, __i8 nSqlFieldId)
		{
			if (SqlDeal_::mCreateFD_ == mSqlDeal) {
				this->runCreateFD(nSql, nName, nSqlFieldId);
			} else if ( (SqlDeal_::mCreatePy_ == mSqlDeal)
				&& ((nSqlFieldId & SqlFieldId_::mPrimary_) > 0) ) {
				this->runCreatePy(nName);
			} else if (SqlDeal_::mSelectFD_ == mSqlDeal) {
				this->runSelectFD(nName);
			} else if (SqlDeal_::mWhere_ == mSqlDeal) {
				this->runWhere(nValue, nName);
			} else if (SqlDeal_::mInsertFD_ == mSqlDeal) {
				this->runInsertFD(nValue);
			} else if (SqlDeal_::mUpdateFD_ == mSqlDeal) {
				this->runUpdateFD(nValue, nName);
			} else if ( (SqlDeal_::mInsertUpdateFD_ == mSqlDeal) 
				&& ((nSqlFieldId & SqlFieldId_::mPrimary_) == 0)) {
				this->runInsertUpdateFD(nName);
			} else {
			}
		}
		
	public:
		SqlCommand();
		~SqlCommand();
		
	private:
        static const char * mValueBegin;
		static const char * mValueEnd;
        static const char * mFieldBegin;
		static const char * mFieldEnd;
		
		IDbQuery * mDbQuery;
        SqlDeal_ mSqlDeal;
        string mValue;
        bool mBeg;
        bool mEnd;
	};
	
}
#endif
