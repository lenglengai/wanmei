#include "../../include/Include.h"

#ifdef __WITHMYSQL__
namespace std {

	void SqlCommand::serialize(const char * nName, __i8 nSqlFieldId)
	{
		if (SqlDeal_::mSelect_ == mSqlDeal) {
			this->runSelect(nName);
		} else if ( (SqlDeal_::mInsertUpdate_ == mSqlDeal) 
			&& ((nSqlFieldId & SqlFieldId_::mPrimary_) == 0)){
			this->runInsertUpdate(nName);
		}
	}
	
    void SqlCommand::serialize(bool& nValue, const char * nName, __i8 nSqlFieldId)
	{
		this->runType(nValue, "TINYINT(1)", nName, nSqlFieldId);
	}

    void SqlCommand::serialize(__i8& nValue, const char * nName, __i8 nSqlFieldId)
	{
		this->runType(nValue, "INT(10)", nName, nSqlFieldId);
	}
	
    void SqlCommand::serialize(__i16& nValue, const char * nName, __i8 nSqlFieldId)
	{
		this->runType(nValue, "INT(10)", nName, nSqlFieldId);
	}
	
    void SqlCommand::serialize(__i32& nValue, const char * nName, __i8 nSqlFieldId)
	{
		this->runType(nValue, "INT(10)", nName, nSqlFieldId);
	}
	
    void SqlCommand::serialize(__i64& nValue, const char * nName, __i8 nSqlFieldId)
	{
		this->runType(nValue, "BIGINT", nName, nSqlFieldId);
	}
	
    void SqlCommand::serialize(string& nValue, const char * nName, __i8 nSqlFieldId)
	{
		this->runType(nValue, "VARCHAR(255)", nName, nSqlFieldId);
	}
	
    void SqlCommand::serialize(float& nValue, const char * nName, __i8 nSqlFieldId)
	{
		this->runType(nValue, "FLOAT", nName, nSqlFieldId);
	}
	
    void SqlCommand::serialize(double& nValue, const char * nName, __i8 nSqlFieldId)
	{
		this->runType(nValue, "DOUBLE", nName, nSqlFieldId);
	}
	
	void SqlCommand::runHeadstream(ISqlHeadstream * nSqlStream, bool nDbQuery)
	{
		SqlType_ sqlType_ = nSqlStream->getSqlType();
		if (SqlType_::mDataBase_ == sqlType_) {
			this->runDataBase(nSqlStream);
		} else if (SqlType_::mCreate_ == sqlType_) {
			this->runCreate(nSqlStream);
		} else if (SqlType_::mSelect_ == sqlType_) {
			if (nDbQuery) {
				this->runDbQuery(nSqlStream);
			} else {
				this->runSelect(nSqlStream);
			}
		} else if (SqlType_::mDelete_ == sqlType_) {
            this->runDelete(nSqlStream);
        } else if (SqlType_::mUpdate_ == sqlType_) {
            this->runUpdate(nSqlStream);
        } else if (SqlType_::mInsert_ == sqlType_) {
			this->runInsert(nSqlStream);
        } else if (SqlType_::mInsertUpdate_ == sqlType_) {
			this->runInsertUpdate(nSqlStream);
        } else {
        }
    }
	
	std::string& SqlCommand::getValue()
	{
		return mValue;
	}
	
	void SqlCommand::setDbQuery(IDbQuery * nDbQuery)
	{
		mDbQuery = nDbQuery;
	}
	
	void SqlCommand::runCreate(ISqlHeadstream * nSqlHeadstream)
	{
		mValue += "CREATE TABLE ";
		mValue += mFieldCharacter;
		mValue += nSqlHeadstream->getTableName();
		mValue += mFieldCharacter;
		mValue += "(";
		mBeg = true;
		mSqlDeal = SqlDeal_::mCreate_;
		nSqlHeadstream->runSelect(this);
		mBeg = true;
		mEnd = false;
		mSqlDeal = SqlDeal_::mPrimary_;
		nSqlHeadstream->runSelect(this);
		if (mEnd) {
			mValue += ")";
		}
		mValue += ")ENGINE=MYISAM DEFAULT CHARSET=utf8;";
		mSqlDeal = SqlDeal_::mNone_;
	}

	void SqlCommand::runCreate(const char * nValue, const char * nName, __i8 nSqlFieldId)
	{
		if (false == mBeg) {
           mValue += ",";
        }
        mValue += mFieldCharacter;
        mValue += nName;
        mValue += mFieldCharacter;
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

    void SqlCommand::runPrimary(const char * nName)
	{
        if (false == mBeg) {
            mValue += ",";
        } else {
			mValue += ", PRIMARY KEY (";
        }
		mValue += mFieldCharacter;
		mValue += nName;
		mValue += mFieldCharacter;
		mEnd = true;
		if (mBeg) {
            mBeg = false;
        }
    }
	
	void SqlCommand::runSelect(ISqlHeadstream * nSqlHeadstream)
	{
		mValue += "SELECT ";
		mBeg = true;
		mSqlDeal = SqlDeal_::mSelect_;
		nSqlHeadstream->runSelect(this);
		mValue += " FROM ";
		mValue += mFieldCharacter;
		mValue += nSqlHeadstream->getTableName();
		mValue += mFieldCharacter;
		mValue += " ";
		mSqlDeal = SqlDeal_::mWhere_;
		nSqlHeadstream->runWhere(this);
		mSqlDeal = SqlDeal_::mNone_;
	}
	
	void SqlCommand::runSelect(const char * nName)
	{
        if (false == mBeg) {
            mValue += ",";
        }
        mValue += mFieldCharacter;
        mValue += nName;
        mValue += mFieldCharacter;
        if (mBeg) {
            mBeg = false;
        }
    }
	
	void SqlCommand::runWhere(string& nValue, const char * nName)
	{
		mValue += "WHERE ";
		mValue += mFieldCharacter;
		mValue += nName;
		mValue += mFieldCharacter;
		mValue += "=";
		mValue += mValueCharacter;
		mValue += nValue;
		mValue += mValueCharacter;
		mValue += " ";
	}
	
	void SqlCommand::runDelete(ISqlHeadstream * nSqlHeadstream)
	{
		mValue += "DELETE FROM ";
		mValue += mFieldCharacter;
		mValue += nSqlHeadstream->getTableName();
		mValue += mFieldCharacter;
		mValue += " ";
		mSqlDeal = SqlDeal_::mWhere_;
		nSqlHeadstream->runWhere(this);
		mSqlDeal = SqlDeal_::mNone_;
    }
	
	void SqlCommand::runUpdate(ISqlHeadstream * nSqlHeadstream)
	{
		mValue += "UPDATE ";
		mValue += mFieldCharacter;
		mValue += nSqlHeadstream->getTableName();
		mValue += mFieldCharacter;
		mValue += " SET ";
		mBeg = true;
		mSqlDeal = SqlDeal_::mUpdate_;
		nSqlHeadstream->runSelect(this);
		mValue += " ";
		mSqlDeal = SqlDeal_::mWhere_;
		nSqlHeadstream->runWhere(this);
		mSqlDeal = SqlDeal_::mNone_;
    }
	
	void SqlCommand::runUpdate(string& nValue, const char * nName)
	{
		if (false == mBeg) {
			mValue += ",";
        }
        mValue += mFieldCharacter;
        mValue += nName;
        mValue += mFieldCharacter;
        mValue += "=";
        mValue += mValueCharacter;
        mValue += nValue;
        mValue += mValueCharacter;
        if (mBeg) {
            mBeg = false;
        }
	}
	
	void SqlCommand::runInsert(ISqlHeadstream * nSqlHeadstream)
	{
		mValue += "INSERT INTO ";
		mValue += mFieldCharacter;
		mValue += nSqlHeadstream->getTableName();
		mValue += mFieldCharacter;
		mValue += "(";
		mBeg = true;
		mSqlDeal = SqlDeal_::mSelect_;
		nSqlHeadstream->runSelect(this);
		mValue += ")VALUES(";
		mBeg = true;
		mSqlDeal = SqlDeal_::mInsert_;
		nSqlHeadstream->runSelect(this);
		mValue += ")";
		mSqlDeal = SqlDeal_::mNone_;
    }
	
	void SqlCommand::runInsertUpdate(ISqlHeadstream * nSqlHeadstream)
	{
		mValue += "INSERT INTO ";
		mValue += mFieldCharacter;
		mValue += nSqlHeadstream->getTableName();
		mValue += mFieldCharacter;
		mValue += "(";
		mBeg = true;
		mSqlDeal = SqlDeal_::mSelect_;
		nSqlHeadstream->runSelect(this);
		mValue += ")VALUES(";
		mBeg = true;
		mSqlDeal = SqlDeal_::mInsert_;
		nSqlHeadstream->runSelect(this);
		mValue += ")ON DUPLICATE KEY UPDATE ";
		mBeg = true;
		mSqlDeal = SqlDeal_::mInsertUpdate_;
		nSqlHeadstream->runSelect(this);
		mSqlDeal = SqlDeal_::mNone_;
	}

	void SqlCommand::runInsertUpdate(const char * nName)
	{
		if (false == mBeg) {
			mValue += ",";
        }
		mValue += mFieldCharacter;
		mValue += nName;
		mValue += mFieldCharacter;
		mValue += "=VALUES(";
		mValue += mFieldCharacter;
		mValue += nName;
		mValue += mFieldCharacter;
		mValue += ")";
		if (mBeg) {
			mBeg = false;
        }
    }
	
	void SqlCommand::runDbQuery(ISqlHeadstream * nSqlHeadstream)
	{
		mSqlDeal = SqlDeal_::mQuery_;
		nSqlHeadstream->runSelect(this);
	}
	
	void SqlCommand::runDataBase(ISqlHeadstream * nSqlHeadstream)
	{
		mValue += "CREATE DATABASE ";
		mValue += nSqlHeadstream->getTableName();
		mValue += ";";
	}
	
	void SqlCommand::runClear()
	{
		mSqlDeal = SqlDeal_::mNone_;
		mValue = "";
		mName = "";
		mBeg = false;
		mEnd = false;
		
		mDbQuery = nullptr;
	}
	
	SqlCommand::SqlCommand()
	{
		this->runClear();
	}
	
	SqlCommand::~SqlCommand()
	{
		this->runClear();
	}
	
	const char * SqlCommand::mValueCharacter = "'";
	const char * SqlCommand::mFieldCharacter = "";
	
}
#endif
