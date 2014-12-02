#include "../../include/Include.h"

#ifdef __WITHMYSQL__
namespace std {
	
	__i16 MySqlConnection::runSql(ISqlHeadstream * nSqlHeadstream)
	{
		SqlCommand sqlCommand;
		sqlCommand.runHeadstream(nSqlHeadstream);
		std::string& strSql = sqlCommand.getValue();
		for (int i = 0; i < 2; ++i) {
			int r = mysql_real_query(&mMYSQL, strSql.c_str(), strSql.length());
			if (0 == r) break;
			if (i > 0) {
				LogService& logService_ = Singleton<LogService>::instance();
				logService_.logError(log_1(mysql_error(&mMYSQL)));
				return ERRORINT::DBERROR;
			}
			int errorNo = mysql_errno(&mMYSQL);
			if (errorNo == CR_SERVER_GONE_ERROR || errorNo == CR_SERVER_LOST) {
				this->runActivate(true);
				continue;
			}
		}
		if ( SqlType_::mSelect_ == nSqlHeadstream->getSqlType() ) {
			MySqlQuery mySqlQuery(mMYSQL);
			__i16 errorCode = mySqlQuery.runQuery();
			if ( ERRORINT::SUCESS != errorCode) {
				return errorCode;
			}
			sqlCommand.setDbQuery(&mySqlQuery);
			sqlCommand.runHeadstream(nSqlHeadstream, true);
		}
		return ERRORINT::SUCESS;
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
			TimeService& timeService_ = Singleton<TimeService>::instance();
			__i64 currentTime_ = timeService_.getLocalTime();
			if (currentTime_ > mTimeStamp) {
				this->runDisconnect();
				this->runConnect();
			}
		}
	}
	
	void MySqlConnection::runConnect()
	{
		if (!mConnected) {
			internalConnect();
			TimeService& timeService_ = Singleton<TimeService>::instance();
			mTimeStamp = timeService_.getLocalTime();
			mTimeStamp += mDataBase->getMaxUsedSeconds();
			mConnected = true;
			mBusy = false;
		}
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
	
	void MySqlConnection::internalConnect()
	{
	    if ( nullptr == mysql_init(&mMYSQL) ) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1("mysql_init"));
			return;
		}
		if ( nullptr == mysql_real_connect(&mMYSQL,
			mDataBase->getHostName().c_str(),
			mDataBase->getUserName().c_str(),
			mDataBase->getPassword().c_str(),
			mDataBase->getDbName().c_str(),
			mDataBase->getPort(), nullptr, 0) ) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(mysql_error(&mMYSQL)));
			return;
		}
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
