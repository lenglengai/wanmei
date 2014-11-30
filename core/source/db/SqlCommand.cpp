

namespace std {

    void SqlCommand::serialize(bool& nValue, string& nName, SqlFieldId_ nSqlFieldId)
	{
		this->runType(nValue, "TINYINT(1)", nName, nSqlFieldId);
	}

    void SqlCommand::serialize(__i8& nValue, string& nName, SqlFieldId_ nSqlFieldId)
	{
		this->runType(nValue, "INT(10)", nName, nSqlFieldId);
	}
		
	void SqlCommand::serialize(std::list<__i8>& nValue, string& nName)
	{
        if (SqlDeal_.mWhere_ == mSqlDeal) {
            this._runWhere(nValue, nName);
        }
	}

    void SqlCommand::serialize(__i16& nValue, string& nName, SqlFieldId_ nSqlFieldId)
	{
		this->runType(nValue, "INT(10)", nName, nSqlFieldId);
	}
	
    void SqlCommand::serialize(std::list<__i16>& nValue, string& nName)
	{
        if (SqlDeal_.mWhere_ == mSqlDeal) {
            this._runWhere(nValue, nName);
        }
	}

    void SqlCommand::serialize(__i32& nValue, string& nName, SqlFieldId_ nSqlFieldId)
	{
		this->runType(nValue, "INT(10)", nName, nSqlFieldId);
	}
	
    void SqlCommand::serialize(std::list<__i32>& nValue, string& nName)
	{
        if (SqlDeal_.mWhere_ == mSqlDeal) {
            this._runWhere(nValue, nName);
        }
	}

    void SqlCommand::serialize(__i64& nValue, string& nName, SqlFieldId_ nSqlFieldId)
	{
		this->runType(nValue, "BIGINT", nName, nSqlFieldId);
	}
	
    void SqlCommand::serialize(std::list<__i64>& nValue, string& nName)
	{
        if (SqlDeal_.mWhere_ == mSqlDeal) {
            this._runWhere(nValue, nName);
        }
	}

    void SqlCommand::serialize(string& nValue, string& nName, SqlFieldId_ nSqlFieldId)
	{
		this->runType(nValue, "VARCHAR(255)", nName, nSqlFieldId);
	}
	
    void SqlCommand::serialize(std::list<string>& nValue, string& nName)
	{
        if (SqlDeal_.mWhere_ == mSqlDeal) {
            this._runWhere(nValue, nName);
        }
	}

    void SqlCommand::serialize(float& nValue, string& nName, SqlFieldId_ nSqlFieldId)
	{
		this->runType(nValue, "FLOAT", nName, nSqlFieldId);
	}
	
    void SqlCommand::serialize(std::list<float>& nValue, string& nName)
	{
        if (SqlDeal_.mWhere_ == mSqlDeal) {
            this._runWhere(nValue, nName);
        }
	}

    void SqlCommand::serialize(double& nValue, string& nName, SqlFieldId_ nSqlFieldId)
	{
		this->runType(nValue, "DOUBLE", nName, nSqlFieldId);
	}
	
    void SqlCommand::serialize(std::list<double>& nValue, string& nName)
	{
        if (SqlDeal_.mWhere_ == mSqlDeal) {
            this._runWhere(nValue, nName);
        }
	}

    void SqlCommand::serialize(char *& nValue, __i32& nLength, string& nName, SqlFieldId_ nSqlFieldId)
	{
	}
	
	void SqlCommand::runCreate(const char * nValue, string& nName, SqlFieldId_ nSqlFieldId)
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

    void SqlCommand::runPrimary(string& nName)
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
	
	void SqlCommand::runSelect(string& nName)
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
	
    void SqlCommand::runInsertUpdate(string& nName)
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

	void SqlCommand::runHeadstream(ISqlHeadstream * nSqlStream)
	{
		SqlType_ sqlType_ = nSqlStream->getSqlType();
		if (SqlType_::mCreate_ == sqlType_) {
			this->runCreate(nSqlStream);
		} else if (SqlType_::mSelect_ == sqlType_) {
			this->runSelect(nSqlStream);
		} else if (SqlType_::mInsert_ == sqlType_) {
			this->runInsert(nSqlStream);
        } else if (SqlType_::mInsertUpdate_ == sqlType_) {
            this->runInsertUpdate(nSqlStream);
        } else if (SqlType_::mInsertUpdateEx_ == sqlType_) {
            this->runInsertUpdateEx(nSqlStream);
        } else if (SqlType_::mUpdate_ == sqlType_) {
            this->runUpdate(nSqlStream);
        } else if (SqlType_::mDelete_ == sqlType_) {
            this->runDelete(nSqlStream);
        } else {
        }
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
	
	void SqlCommand::runInsert(ISqlHeadstream * nSqlHeadstream)
	{
		mValue += "INSERT INTO ";
		mValue += mFieldCharacter;
		mValue += nSqlHeadstream->getTableName();
		mValue += mFieldCharacter;
		mValue += " (";
		mBeg = true;
		mSqlDeal = SqlDeal_::mSelect_;
		nSqlHeadstream->runSelect(this);
		mValue += ") VALUES (";
		mBeg = true;
		mSqlDeal = SqlDeal_::mInsert_;
		nSqlHeadstream->runSelect(this);
		mValue += ") ";
		mSqlDeal = SqlDeal_::mWhere_;
		nSqlHeadstream->runWhere(this);
		mSqlDeal = SqlDeal_::mNone_;
    }
	
	void SqlCommand::runInsertUpdate(ISqlHeadstream * nSqlHeadstream)
	{
		mValue += "INSERT INTO ";
		mValue += mFieldCharacter;
		mValue += nSqlHeadstream->getTableName();
		mValue += mFieldCharacter;
		mValue += " (";
		mBeg = true;
		mSqlDeal = SqlDeal_::mSelect_;
		nSqlHeadstream->runSelect(this);
		mValue += ") VALUES (";
		mBeg = true;
		mSqlDeal = SqlDeal_::mInsert_;
		nSqlHeadstream->runSelect(this);
		mValue += ") ";
		mSqlDeal = SqlDeal_::mInsertUpdate_;
		nSqlHeadstream->runSelect(this);
		mSqlDeal = SqlDeal_::mWhere_;
		nSqlHeadstream->runWhere(this);
		mSqlDeal = SqlDeal_::mNone_;
	}
	
	void SqlCommand::runInsertUpdateEx(ISqlHeadstream * nSqlHeadstream)
	{
		mValue += "INSERT INTO ";
		mValue += mFieldCharacter;
		mValue += nSqlHeadstream->getTableName();
		mValue += mFieldCharacter;
		mValue += " VALUES (";
		mBeg = true;
		mSqlDeal = SqlDeal_::mInsertUpdateE_;
		nSqlHeadstream->runSelect(this);
		mValue += ") ON DUPLICATE KEY UPDATE ";
		mBeg = true;
		mSqlDeal = SqlDeal_::mInsertUpdateEx_;
		nSqlHeadstream->runSelect(this);
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
		
	const char * SqlCommand::mValueCharacter = "'";
	const char * SqlCommand::mFieldCharacter = "`";
	const char * SqlCommand::mUpdateCharacter = "@";
	
}
