#include "../Include.h"
#include "MySqlConnection.h"

#ifdef __WITHMYSQL__
namespace std {
	
	__i16 MySqlConnection::runSql(ISqlHeadstream * nSqlHeadstream)
	{
		SqlCommand sqlCommand;
		sqlCommand.runHeadstream(nSqlHeadstream);
		const std::string& strSql = sqlCommand.getValue();
		for (int i = 0; i < 2; ++i) {
			int r = mysql_real_query(&mMYSQL, strSql.c_str(), strSql.length());
			if (0 == r) break;
			if (i > 0) {
				LogService& logService_ = Service<LogService>::instance();
				logService_.logError(log_1(mysql_error(&mMYSQL)));
				return Error_::mDbError_;
			}
			int errorNo = mysql_errno(&mMYSQL);
			if (errorNo == CR_SERVER_GONE_ERROR || errorNo == CR_SERVER_LOST) {
				this->runActivate(true);
				continue;
			}
		}
		if ( SqlType_::mSelect_ == nSqlHeadstream->getSqlType() ) {
			MySqlQuery mySqlQuery(mMYSQL);
			__i16 errorCode_ = mySqlQuery.runQuery();
			if (Error_::mSucess_ != errorCode_) {
				return errorCode_;
			}
			sqlCommand.runQuery(nSqlHeadstream, &mySqlQuery);
		}
		return Error_::mSucess_;
	}
	
	__i16 MySqlConnection::runSql(const char * nSql)
	{
		for (int i = 0; i < 2; ++i) {
			int r = mysql_real_query(&mMYSQL, nSql, strlen(nSql));
			if (0 == r) break;
			if (i > 0) {
				LogService& logService_ = Service<LogService>::instance();
				logService_.logError(log_1(mysql_error(&mMYSQL)));
				return Error_::mDbError_;
			}
			int errorNo = mysql_errno(&mMYSQL);
			if (errorNo == CR_SERVER_GONE_ERROR || errorNo == CR_SERVER_LOST) {
				this->runActivate(true);
				continue;
			}
		}
		return Error_::mSucess_;
	}
	
	void MySqlConnection::runRecycle()
	{
		mBusy = false;
	}
	
	bool MySqlConnection::runGet()
	{
		this->runActivate();
		if ( (!mBusy) && mConnected ) {
			mBusy = true;
			return true;
		}
		return false;
	}
	
	void MySqlConnection::runActivate(bool nForce)
	{
		if ( (!mConnected ) || nForce ) {
			this->runDisconnect();
			this->runConnect();
			return;
		}
		if (!mBusy) {
			TimeService& timeService_ = Service<TimeService>::instance();
			__i64 currentTime_ = timeService_.getLocalTime();
			if (currentTime_ > mTimeStamp) {
				this->runDisconnect();
				this->runConnect();
			}
		}
	}
	
	bool MySqlConnection::runConnect()
	{
		if (mConnected) return true;
		if ( internalConnect() ) {
			TimeService& timeService_ = Service<TimeService>::instance();
			mTimeStamp = timeService_.getLocalTime();
			mTimeStamp += mDataBase->getMaxUsedSeconds();
			mConnected = true;
			mBusy = false;
			return true;
		}
		return false;
	}
	
	void MySqlConnection::runDisconnect()
	{
		if (mConnected) {
			internalDisconnect();
			mConnected = false;
			mBusy = false;
			mTimeStamp = 0;
		}
	}
	
	bool MySqlConnection::runCreate()
	{
		if ( internalCreate() ) {
			TimeService& timeService_ = Service<TimeService>::instance();
			mTimeStamp = timeService_.getLocalTime();
			mTimeStamp += mDataBase->getMaxUsedSeconds();
			mConnected = true;
			mBusy = false;
			return true;
		}
		this->internalDisconnect();
		return false;
	}
	
	bool MySqlConnection::internalCreate()
	{
	    if ( nullptr == mysql_init(&mMYSQL) ) {
			LogService& logService_ = Service<LogService>::instance();
			logService_.logError(log_1("mysql_init"));
			return false;
		}
		if ( nullptr == mysql_real_connect(&mMYSQL,
			mDataBase->getHostName().c_str(),
			mDataBase->getUserName().c_str(),
			mDataBase->getPassword().c_str(),
			"",
			mDataBase->getPort(), nullptr, 0) ) {
			LogService& logService_ = Service<LogService>::instance();
			logService_.logError(log_1(mysql_error(&mMYSQL)));
			return false;
		}
		string strSql_ = "CREATE DATABASE ";
		strSql_ += mDataBase->getDbName();
		if ( Error_::mSucess_ != this->runSql(strSql_.c_str()) ) {
			return false;
		}
		strSql_ = "USE "; strSql_ += mDataBase->getDbName();
		if ( Error_::mSucess_ != this->runSql(strSql_.c_str()) ) {
			return false;
		}
		return true;
	}
	
	bool MySqlConnection::internalConnect()
	{
	    if ( nullptr == mysql_init(&mMYSQL) ) {
			LogService& logService_ = Service<LogService>::instance();
			logService_.logError(log_1("mysql_init"));
			return false;
		}
		if ( nullptr == mysql_real_connect(&mMYSQL,
			mDataBase->getHostName().c_str(),
			mDataBase->getUserName().c_str(),
			mDataBase->getPassword().c_str(),
			mDataBase->getDbName().c_str(),
			mDataBase->getPort(), nullptr, 0) ) {
			LogService& logService_ = Service<LogService>::instance();
			logService_.logError(log_1(mysql_error(&mMYSQL)));
			return false;
		}
		return true;
	}
	
	void MySqlConnection::internalDisconnect()
	{
		::mysql_close(&mMYSQL);
	}
	
	MySqlConnection::MySqlConnection(IDataBase * nDataBase)
		: mDataBase (nDataBase)
		, mBusy (false)
		, mConnected (false)
		, mTimeStamp (0)
	{
	}
	
	MySqlConnection::~MySqlConnection()
	{
		mDataBase = nullptr;
		mConnected = false;
		mTimeStamp = 0;
		mBusy = false;
	}
	
}
#endif
