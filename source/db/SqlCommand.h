#pragma once

#ifdef __WITHSQL__
namespace std {
	
	class SqlCommand : noncopyable
	{
	public:
		void serialize(const char * nName, __i8 nSqlFieldId = SqlFieldId_::mNone_);
		
        void serialize(bool& nValue, const char * nName, __i8 nSqlFieldId = SqlFieldId_::mNone_);

        void serialize(__i8& nValue, const char * nName, __i8 nSqlFieldId = SqlFieldId_::mNone_);

        void serialize(__i16& nValue, const char * nName, __i8 nSqlFieldId = SqlFieldId_::mNone_);

        void serialize(__i32& nValue, const char * nName, __i8 nSqlFieldId = SqlFieldId_::mNone_);

        void serialize(__u32& nValue, const char * nName, __i8 nSqlFieldId = SqlFieldId_::mNone_);

        void serialize(__i64& nValue, const char * nName, __i8 nSqlFieldId = SqlFieldId_::mNone_);

        void serialize(string& nValue, const char * nName, __i8 nSqlFieldId = SqlFieldId_::mNone_);

        void serialize(float& nValue, const char * nName, __i8 nSqlFieldId = SqlFieldId_::mNone_);

        void serialize(double& nValue, const char * nName, __i8 nSqlFieldId = SqlFieldId_::mNone_);

		template <class __t>
		void serialize(__t& nValue)
		{
			if (SqlDeal_::mInsert_ == mSqlDeal) {
				this->runInsert(nValue);
			}
		}
		
		template <class __t>
		void serialize(list<shared_ptr<__t> >& nValues)
		{
			if (SqlDeal_::mInsert_ == mSqlDeal) {
				bool first_ = true;
				for (auto& it : nValues) {
					if (!first_) {
						mValue += "),(";
						mBeg = true;
					}
					it->runSelect(this);
					first_ = false;
				}
			}
		}
	public:
		void runHeadstream(ISqlHeadstream * nSqlStream, bool nDbQuery = false);
		void setDbQuery(IDbQuery * nDbQuery);
		const std::string& getValue() const;
		
	private:
		template <typename T>
		void runType(T& nValue, const char * nSql, const char * nName, __i8 nSqlFieldId)
		{
			if (SqlDeal_::mCreate_ == mSqlDeal) {
				this->runCreate(nSql, nName, nSqlFieldId);
			} else if ((SqlDeal_::mPrimary_ == mSqlDeal)
				&& ((nSqlFieldId & SqlFieldId_::mPrimary_) > 0)) {
				this->runPrimary(nName);
			} else if (SqlDeal_::mSelect_ == mSqlDeal) {
				this->runSelect(nName);
			} else if (SqlDeal_::mWhere_ == mSqlDeal) {
				this->runWhere(nValue, nName);
			} else if (SqlDeal_::mUpdate_ == mSqlDeal) {
				this->runUpdate(nValue, nName);
			} else if (SqlDeal_::mInsert_ == mSqlDeal) {
				this->runInsert(nValue);
			} else if ( (SqlDeal_::mInsertUpdate_ == mSqlDeal) 
				&& ((nSqlFieldId & SqlFieldId_::mPrimary_) == 0)){
				this->runInsertUpdate(nName);
			} else if (SqlDeal_::mQuery_ == mSqlDeal) {
				this->runQuery(nValue);
			}
		}
		
		void runCreate(ISqlHeadstream * nSqlHeadstream);
		void runCreate(const char * nValue, const char * nName, __i8 nSqlFieldId);
		void runPrimary(const char * nName);
		
		void runSelect(ISqlHeadstream * nSqlHeadstream);
		void runSelect(const char * nName);
		template <typename __t>
	    void runWhere(__t& nValue, const char * nName)
		{
			mValue += "WHERE ";
			mValue += mFieldCharacter;
            mValue += nName;
			mValue += mFieldCharacter;
			mValue += "=";
            mValue += mValueCharacter;
            mValue += __convert<__t, string>(nValue, ConvertType_::mSql_);
            mValue += mValueCharacter;
            mValue += " ";
        }
		void runWhere(string& nValue, const char * nName);
		
		void runDelete(ISqlHeadstream * nSqlHeadstream);
		
		void runUpdate(ISqlHeadstream * nSqlHeadstream);
		template <typename __t>
		void runUpdate(__t& nValue, const char * nName)
		{
            if (false == mBeg) {
                mValue += ",";
            }
            mValue += mFieldCharacter;
            mValue += nName;
            mValue += mFieldCharacter;
            mValue += "=";
            mValue += mValueCharacter;
            mValue += __convert<__t, string>(nValue, ConvertType_::mSql_);
            mValue += mValueCharacter;
            if (mBeg) {
                mBeg = false;
            }
        }
		void runUpdate(string& nValue, const char * nName);
		
		void runReplace(ISqlHeadstream * nSqlHeadstream);
		void runInsert(ISqlHeadstream * nSqlHeadstream);
		template <typename __t>
        void runInsert(__t& nValue)
		{
            if (false == mBeg) {
                mValue += ",";
            }
            mValue += mValueCharacter;
			mValue += __convert<__t, string>(nValue, ConvertType_::mSql_);
            mValue += mValueCharacter;
            if (mBeg) {
                mBeg = false;
            }
        }
        void runInsert(string& nValue)
		{
            if (false == mBeg) {
                mValue += ",";
            }
            mValue += mValueCharacter;
			mValue += nValue;
            mValue += mValueCharacter;
            if (mBeg) {
                mBeg = false;
            }
        }
		
		void runInsertUpdate(ISqlHeadstream * nSqlHeadstream);
		void runInsertUpdate(const char * nName);
		
		void runDbQuery(ISqlHeadstream * nSqlHeadstream);
		template <typename __t>
        void runQuery(__t& nValue)
		{
			mDbQuery->returnResult(nValue);
        }
		
		void runDataBase(ISqlHeadstream * nSqlHeadstream);
		
		void runSetDB(ISqlHeadstream * nSqlHeadstream);
		
		void runDropDB(ISqlHeadstream * nSqlHeadstream);
		
		void runClear();
		
	public:
		SqlCommand();
		~SqlCommand();
		
	private:
        static const char * mValueCharacter;
        static const char * mFieldCharacter;
		
        SqlDeal_ mSqlDeal;
        string mValue;
        string mName;
        bool mBeg;
        bool mEnd;
		
		IDbQuery * mDbQuery;
	};
	
}
#endif
