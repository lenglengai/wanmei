#include "../../include/Include.h"

namespace std {

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
