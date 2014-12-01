#include "../../include/Include.h"

namespace std {

	__i16 MySqlDataBase::runSql(ISqlHeadstream * nSqlHeadstream)
	{
		DbConnectionPtr& connection_ = this->getConnection();
		if (!connection_) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1("!connection_"));
			return ERRORINT::DBERROR;
		}
		__i16 result_ = connection_->runSql(nSqlHeadstream);
		if ( (ERRORINT::SUCESS == result_) && (nSqlHeadstream->) ) {
			
		}
	}
	
	DbConnectionPtr MySqlDataBase::createConnection()
	{
		return DbConnectionPtr(new MySqlConnection(this));
	}
	
	MySqlDataBase::MySqlDataBase()
	{
	}
	
	MySqlDataBase::~MySqlDataBase()
	{
	}
	
}
