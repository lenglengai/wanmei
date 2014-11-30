#pragma once

namespace std {
	
	class SqlCommand : boost::noncopyable
	{
	public:
        void serialize(bool& nValue, string& nName, SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);

        void serialize(__i8& nValue, string& nName, SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
        void serialize(std::list<__i8>& nValue, string& nName);

        void serialize(__i16& nValue, string& nName, SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
        void serialize(std::list<__i16>& nValue, string& nName);

        void serialize(__i32& nValue, string& nName, SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
        void serialize(std::list<__i32>& nValue, string& nName);

        void serialize(__i64& nValue, string& nName, SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
        void serialize(std::list<__i64>& nValue, string& nName);

        void serialize(string& nValue, string& nName, SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
        void serialize(std::list<string>& nValue, string& nName);

        void serialize(float& nValue, string& nName, SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
        void serialize(std::list<float>& nValue, string& nName);

        void serialize(double& nValue, string& nName, SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
        void serialize(std::list<double>& nValue, string& nName);

        void serialize(char *& nValue, __i32& nLength, string& nName, SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
		
		template <class __t>
        void serialize(__t& nValue, string& nName, SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_)
		{
		}
		
		template <class __t>
        void serialize(std::list<__t>& nValue, string& nName)
		{
		}
		
	public:
		void runHeadstream(ISqlHeadstream * nSqlStream);
		
	private:
		void runCreate(ISqlHeadstream * nSqlHeadstream);
		void runSelect(ISqlHeadstream * nSqlHeadstream);
		void runInsert(ISqlHeadstream * nSqlHeadstream);
		void runInsertUpdate(ISqlHeadstream * nSqlHeadstream);
		void runInsertUpdateEx(ISqlHeadstream * nSqlHeadstream);
		void runUpdate(ISqlHeadstream * nSqlHeadstream);
		void runDelete(ISqlHeadstream * nSqlHeadstream);
		
	private:
		template <typename __t>
	    void runWhere(__t& nValue, string& nName)
		{
            mValue += nName;
            mValue += mValueCharacter;
            mValue += __convert<string, __t>(nValue);
            mValue += mValueCharacter;
            mValue += " ";
        }
		
		template <typename __t>
        void _runWhere(std::list<__t>& nValue, string& nName)
		{
            bool beg_ = true;
            mValue += nName;
            mValue += "(";
            for (auto& i : nValue) {
                if (false == beg_) {
                    mValue += ",";
                }
                mValue += mValueCharacter;
                mValue += __convert<string, __t>(i);
                mValue += mValueCharacter;
                beg_ = false;
            }
            mValue += ") ";
        }
		
		template <typename __t>
        void runInsert(__t& nValue)
		{
            if (false == mBeg) {
                mValue += ",";
            }
            mValue += mValueCharacter;
            mValue += __convert<string, __t>(nValue);
            mValue += mValueCharacter;
            if (mBeg) {
                mBeg = false;
            }
        }
		
		template <typename __t>
		void runInsertUpdateE(string& nName, __t& nValue)
		{
            if (false == mBeg) {
                mValue += ",";
            }
            mValue += mUpdateCharacter;
            mValue += nName;
            if (mBeg) {
                mBeg = false;
            }
            SqlParameter sqlParameter_ = new SqlParameter(nName, nValue);
            mFields.Add(sqlParameter_);
        }
		
		void runCreate(const char * nValue, string& nName, SqlFieldId_ nSqlFieldId);
		void runPrimary(string& nName);
		void runSelect(string& nName);
		void runInsertUpdate(string& nName);
		
		template <typename T>
		void runType(T& nValue, const char * nSql, string& nName, SqlFieldId_ nSqlFieldId)
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
			} else if (SqlDeal_::mInsert_ == mSqlDeal) {
				this->runInsert(nValue);
			} else if (SqlDeal_::mInsertUpdate_ == mSqlDeal) {
				this->runInsertUpdate(nName);
			} else if (SqlDeal_::mInsertUpdateE_ == mSqlDeal) {
				this->runInsertUpdateE(nName, nValue);
			}  else if (SqlDeal_::mInsertUpdateEx_ == mSqlDeal) {
				this->runInsertUpdateEx(nName);
			}  else if (SqlDeal_::mUpdate_ == mSqlDeal) {
				this->runUpdate(nValue, nName);
			} else if (SqlDeal_::mUpdateSelect_ == mSqlDeal) {
				this->updateSelect(nName);
			} else if (SqlDeal_::mUpdateWhen_ == mSqlDeal) {
				this->updateWhen(nValue);
			} else if (SqlDeal_::mUpdateThen_ == mSqlDeal) {
				this->updateThen(nValue, nName);
			} else {
			}
		}
		
	private:
        static const char * mValueCharacter;
        static const char * mFieldCharacter;
        static const char * mUpdateCharacter;
		
		std::list<SqlParameter> mFields;
        std::list<string> mUpdate;
        SqlDeal_ mSqlDeal;
        std::string mValue;
        std::string mName;
        bool mBeg;
        bool mEnd;
	};
	
}
