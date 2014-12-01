#include "../../include/Include.h"

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
				logService_.logError(log_1(mysql_error(mMYSQL)));
				return ERRORINT::DBERROR;
			}
			int errorNo = mysql_errno(&mMYSQL);
			if (errorNo == CR_SERVER_GONE_ERROR || errorNo == CR_SERVER_LOST) {
				this->runActivate(true);
				continue;
			}
		}
		
		return ERRORINT::SUCESS;
	}
	
	void MySqlConnection::internalConnect()
	{
	    if ( nullptr == mysql_init(&mMYSQL) ) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1("mysql_init"));
			return;
		}
		if ( nullptr == mysql_real_connect(&mMYSQL,
			nDataBase->getHostName().c_str(),
			nDataBase->getUserName().c_str(),
			nDataBase->getPassword();.c_str(),
			nDataBase->getDbName().c_str(),
			nDataBase->getPort(), NULL, 0) ) {
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
		: IDbConnection(nDataBase)
	{
	}
	
	MySqlConnection::~MySqlConnection()
	{
	}
	
}
