#include "../../include/Include.h"

#ifdef __WITHMYSQL__
namespace std {
	
    void DataBaseUse::runSelect(SqlCommand * nSqlCommand)
	{
	}
	
    void DataBaseUse::runWhere(SqlCommand * nSqlCommand)
	{
	}
	
    const char * DataBaseUse::getTableName()
	{
		return "wanmei";
	}
	
    SqlType_ DataBaseUse::getSqlType()
	{
		return SqlType_::mSetDB_;
	}
	
}
#endif
