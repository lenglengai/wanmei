#include "../Include.h"

#ifdef __WITHSQL__
namespace std {

    void SqlCommand::runBool(bool& nValue, const char * nName, __i8 nSqlFieldId)
	{
		if ( SqlDeal_::mQuery_ == mSqlDeal ) {
			mDbQuery->runBool(nValue);
		} else {
			this->runType(nValue, "TINYINT", nName, nSqlFieldId);
		}
	}

    void SqlCommand::runInt8(__i8& nValue, const char * nName, __i8 nSqlFieldId)
	{
		if ( SqlDeal_::mQuery_ == mSqlDeal ) {
			mDbQuery->runInt8(nValue);
		} else {
			this->runType(nValue, "TINYINT", nName, nSqlFieldId);
		}
	}
	
    void SqlCommand::runInt16(__i16& nValue, const char * nName, __i8 nSqlFieldId)
	{
		if ( SqlDeal_::mQuery_ == mSqlDeal ) {
			mDbQuery->runInt16(nValue);
		} else {
			this->runType(nValue, "SMALLINT", nName, nSqlFieldId);
		}
	}
	
    void SqlCommand::runInt32(__i32& nValue, const char * nName, __i8 nSqlFieldId)
	{
		if ( SqlDeal_::mQuery_ == mSqlDeal ) {
			mDbQuery->runInt32(nValue);
		} else {
			this->runType(nValue, "INT", nName, nSqlFieldId);
		|
	}
	
    void SqlCommand::runInt64(__i64& nValue, const char * nName, __i8 nSqlFieldId)
	{
		if ( SqlDeal_::mQuery_ == mSqlDeal ) {
			mDbQuery->runInt64(nValue);
		} else {
			this->runType(nValue, "BIGINT", nName, nSqlFieldId);
		}
	}
	
    void SqlCommand::runString(string& nValue, const char * nName, __i8 nSize, __i8 nSqlFieldId)
	{
		if ( SqlDeal_::mQuery_ == mSqlDeal ) {
			mDbQuery->runString(nValue);
		} else {
			string charId_ = "CHAR(";
			if ( nSize > 255 ) {
				charId_ = "VARCHAR(";
			}
			charId_ += __convert<__i8, string>(nSize); charId_ += ")";
			this->runType(nValue, charId_.c_str(), nName, nSqlFieldId);
		}
	}
	
    void SqlCommand::runFloat(float& nValue, const char * nName, __i8 nSqlFieldId)
	{
		if ( SqlDeal_::mQuery_ == mSqlDeal ) {
			mDbQuery->runFloat(nValue);
		} else {
			this->runType(nValue, "FLOAT", nName, nSqlFieldId);
		}
	}
	
    void SqlCommand::runDouble(double& nValue, const char * nName, __i8 nSqlFieldId)
	{
		if ( SqlDeal_::mQuery_ == mSqlDeal ) {
			mDbQuery->runDouble(nValue);
		} else {
			this->runType(nValue, "DOUBLE", nName, nSqlFieldId);
		}
	}
	
	void SqlCommand::runData(char *& nValue, __i16& nSize, const char * nName, __i8 nSqlFieldId = SqlFieldId_::mNone_)
	{
		if ( SqlDeal_::mQuery_ == mSqlDeal ) {
			mDbQuery->runData(nValue, nSize);
		} else {
			this->runType(nValue, "BLOB", nName, nSqlFieldId);
		}
	}
	
	void SqlCommand::runHeadstream(ISqlHeadstream * nSqlStream)
	{
		SqlType_ sqlType_ = nSqlStream->getSqlType();
		if (SqlType_::mCreateDB_ == sqlType_) {
			this->runCreateDB(nSqlStream);
		} else if (SqlType_::mDropDB_ == sqlType_) {
			this->runDropDB(nSqlStream);
		} else if (SqlType_::mSetDB_ == sqlType_) {
			this->runSetDB(nSqlStream);
		} else if (SqlType_::mCreateTB_ == sqlType_) {
			this->runCreateTB(nSqlStream);
		}  else if (SqlType_::mDropTB_ == sqlType_) {
			this->runDropTB(nSqlStream);
		} else if (SqlType_::mSelect_ == sqlType_) {
			this->runSelect(nSqlStream);
		} else if (SqlType_::mInsert_ == sqlType_) {
			this->runInsert(nSqlStream);
        } else if (SqlType_::mReplace_ == sqlType_) {
			this->runReplace(nSqlStream);
        } else if (SqlType_::mDelete_ == sqlType_) {
			this->runDelete(nSqlStream);
        } else if (SqlType_::mUpdate_ == sqlType_) {
			this->runUdate(nSqlStream);
        } else if (SqlType_::mInsertUpdate_ == sqlType_) {
			this->runInsertUdate(nSqlStream);
        } else {
        }
    }
	
	void SqlCommand::runCreateDB(ISqlHeadstream * nSqlHeadstream)
	{
	#ifdef __WITHMYSQL__
		mValue += "CREATE DATABASE IF NOT EXISTS ";
		mValue += nSqlHeadstream->getTableName();
		mValue += ";";
	#endif
	}
	
	void SqlCommand::runDropDB(ISqlHeadstream * nSqlHeadstream)
	{
	#ifdef __WITHMYSQL__
		mValue += "DROP DATABASE IF EXISTS ";
		mValue += nSqlHeadstream->getTableName();
		mValue += ";";
	#endif
	}
	
	void SqlCommand::runSetDB(ISqlHeadstream * nSqlHeadstream)
	{
	#ifdef __WITHMYSQL__
		mValue += "Use ";
		mValue += nSqlHeadstream->getTableName();
		mValue += ";";
	#endif
	}
	
	void SqlCommand::runCreateTB(ISqlHeadstream * nSqlHeadstream)
	{
		mValue += "CREATE TABLE ";
		mValue += mFieldBegin;
		mValue += nSqlHeadstream->getTableName();
		mValue += mFieldEnd;
		mValue += "(";
		mBeg = true;
		mSqlDeal = SqlDeal_::mCreateFD_;
		nSqlHeadstream->runSelect(this);
		mBeg = true;
		mEnd = false;
		mSqlDeal = SqlDeal_::mPrimary_;
		nSqlHeadstream->runSelect(this);
		if (mEnd) {
			mValue += ")";
		}
	#ifdef __WITHMYSQL__
		mValue += ")ENGINE=MYISAM DEFAULT CHARSET=utf8;";
	#endif
	#ifdef __WITHSQLITE__
		mValue += ");";
	#endif
		mSqlDeal = SqlDeal_::mNone_;
	}
	
	void SqlCommand::runDropTB(ISqlHeadstream * nSqlHeadstream)
	{
		mValue += "DROP TABLE IF EXISTS ";
		mValue += nSqlHeadstream->getTableName();
		mValue += ";";
	}
	
	void SqlCommand::runSelect(ISqlHeadstream * nSqlHeadstream)
	{
		mValue += "SELECT ";
		mBeg = true;
		mSqlDeal = SqlDeal_::mSelectFD_;
		nSqlHeadstream->runSelect(this);
		mValue += " FROM ";
		mValue += mFieldBegin;
		mValue += nSqlHeadstream->getTableName();
		mValue += mFieldEnd;
		mValue += " ";
		mSqlDeal = SqlDeal_::mWhere_;
		nSqlHeadstream->runWhere(this);
		mSqlDeal = SqlDeal_::mNone_;
	}
	
	void SqlCommand::runInsert(ISqlHeadstream * nSqlHeadstream)
	{
		mValue += "INSERT INTO ";
		mValue += mFieldBegin;
		mValue += nSqlHeadstream->getTableName();
		mValue += mFieldEnd;
		mValue += "(";
		mBeg = true;
		mSqlDeal = SqlDeal_::mSelectFD_;
		nSqlHeadstream->runSelect(this);
		mValue += ")VALUES(";
		mBeg = true;
		mSqlDeal = SqlDeal_::mInsertFD_;
		nSqlHeadstream->runSelect(this);
		mValue += ")";
		mSqlDeal = SqlDeal_::mNone_;
    }
	
	void SqlCommand::runReplace(ISqlHeadstream * nSqlHeadstream)
	{
		mValue += "REPLACE INTO ";
		mValue += mFieldBegin;
		mValue += nSqlHeadstream->getTableName();
		mValue += mFieldEnd;
		mValue += "(";
		mBeg = true;
		mSqlDeal = SqlDeal_::mSelectFD_;
		nSqlHeadstream->runSelect(this);
		mValue += ")VALUES(";
		mBeg = true;
		mSqlDeal = SqlDeal_::mInsertFD_;
		nSqlHeadstream->runSelect(this);
		mValue += ")";
		mSqlDeal = SqlDeal_::mNone_;
	}
	
	void SqlCommand::runDelete(ISqlHeadstream * nSqlHeadstream)
	{
		mValue += "DELETE FROM ";
		mValue += mFieldBegin;
		mValue += nSqlHeadstream->getTableName();
		mValue += mFieldEnd;
		mValue += " ";
		mSqlDeal = SqlDeal_::mWhere_;
		nSqlHeadstream->runWhere(this);
		mSqlDeal = SqlDeal_::mNone_;
    }
	
	void SqlCommand::runUpdate(ISqlHeadstream * nSqlHeadstream)
	{
		mValue += "UPDATE ";
		mValue += mFieldBegin;
		mValue += nSqlHeadstream->getTableName();
		mValue += mFieldEnd;
		mValue += " SET ";
		mBeg = true;
		mSqlDeal = SqlDeal_::mUpdateFD_;
		nSqlHeadstream->runSelect(this);
		mValue += " ";
		mSqlDeal = SqlDeal_::mWhere_;
		nSqlHeadstream->runWhere(this);
		mSqlDeal = SqlDeal_::mNone_;
    }
	
	void SqlCommand::runInsertUpdate(ISqlHeadstream * nSqlHeadstream)
	{
		mValue += "INSERT INTO ";
		mValue += mFieldBegin;
		mValue += nSqlHeadstream->getTableName();
		mValue += mFieldEnd;
		mValue += "(";
		mBeg = true;
		mSqlDeal = SqlDeal_::mSelectFD_;
		nSqlHeadstream->runSelect(this);
		mValue += ")VALUES(";
		mBeg = true;
		mSqlDeal = SqlDeal_::mInsertFD_;
		nSqlHeadstream->runSelect(this);
		mValue += ")ON DUPLICATE KEY UPDATE ";
		mBeg = true;
		mSqlDeal = SqlDeal_::mInsertUpdateFD_;
		nSqlHeadstream->runSelect(this);
		mSqlDeal = SqlDeal_::mNone_;
	}
	
	void SqlCommand::runQuery(ISqlHeadstream * nSqlHeadstream, IDbQuery * nDbQuery)
	{
		mDbQuery = nDbQuery;
		mSqlDeal = SqlDeal_::mQuery_;
		nSqlHeadstream->runSelect(this);
	}
	
	void SqlCommand::runInsertUpdateFD(const char * nName)
	{
		if (false == mBeg) {
			mValue += ",";
        }
		mValue += mFieldBegin;
		mValue += nName;
		mValue += mFieldEnd;
		mValue += "=VALUES(";
		mValue += mFieldBegin;
		mValue += nName;
		mValue += mFieldEnd;
		mValue += ")";
		if (mBeg) {
			mBeg = false;
        }
    }
	
	void SqlCommand::runCreateFD(const char * nValue, const char * nName, __i8 nSqlFieldId)
	{
		if (false == mBeg) {
           mValue += ",";
        }
        mValue += mFieldBegin;
        mValue += nName;
        mValue += mFieldEnd;
        mValue += " ";
        mValue += nValue;
        if ((nSqlFieldId & SqlFieldId_::mZeroFill_) > 0) {
            mValue += " ZEROFILL";
        }
        if ((nSqlFieldId & SqlFieldId_::mBinary_) > 0) {
            mValue += " BINARY";
        }
        if ((nSqlFieldId & SqlFieldId_::mNotNull_) > 0) {
            mValue += " NOT NULL";
        }
        if ((nSqlFieldId & SqlFieldId_::mAutoIncremet_) > 0) {
           mValue += " AUTO_INCREMENT";
        }
        if (mBeg) {
            mBeg = false;
        }
    }
	
    void SqlCommand::runCreatePy(const char * nName)
	{
        if (false == mBeg) {
            mValue += ",";
        } else {
			mValue += ", PRIMARY KEY (";
        }
		mValue += mFieldBegin;
		mValue += nName;
		mValue += mFieldEnd;
		mEnd = true;
		if (mBeg) {
            mBeg = false;
        }
    }
	
	void SqlCommand::runSelectFD(const char * nName)
	{
        if (false == mBeg) {
            mValue += ",";
        }
        mValue += mFieldBegin;
        mValue += nName;
        mValue += mFieldEnd;
        if (mBeg) {
            mBeg = false;
        }
    }
	
	void SqlCommand::runWhere(string& nValue, const char * nName)
	{
		mValue += "WHERE ";
		mValue += nName;
		mValue += nValue;
		mValue += ";";
	}
	
    void SqlCommand::runInsertFD(string& nValue)
	{
		if (false == mBeg) {
           mValue += ",";
        }
        mValue += mValueBegin;
		mValue += nValue;
        mValue += mValueEnd;
        if (mBeg) {
            mBeg = false;
        }
    }

	void SqlCommand::runUpdateFD(string& nValue, const char * nName)
	{
		if (false == mBeg) {
			mValue += ",";
        }
        mValue += mFieldBegin;
        mValue += nName;
        mValue += mFieldEnd;
        mValue += "=";
        mValue += mValueBegin;
        mValue += nValue;
        mValue += mValueEnd;
        if (mBeg) {
            mBeg = false;
        }
	}
	
	const string& SqlCommand::getValue() const
	{
		return mValue;
	}
	
	void SqlCommand::runClear()
	{
		mSqlDeal = SqlDeal_::mNone_;
		mValue = "";
		mBeg = false;
		mEnd = false;
		
		mDbQuery = nullptr;
	}
	
	const char * SqlCommand::mValueBegin = "'";
	const char * SqlCommand::mValueEnd = "'";
	const char * SqlCommand::mFieldBegin = "";
	const char * SqlCommand::mFieldEnd = "";
	
}
#endif
