#include "../../include/Include.h"

#ifdef __WITHMYSQL__
namespace std {
	
    void DataBaseCreate::runSelect(SqlCommand * nSqlCommand)
	{
	}
	
    void DataBaseCreate::runWhere(SqlCommand * nSqlCommand)
	{
	}
	
    const char * DataBaseCreate::getTableName()
	{
		return "wanmei";
	}
	
    SqlType_ DataBaseCreate::getSqlType()
	{
		return SqlType_::mDataBase_;
	}
	
}
#endif
