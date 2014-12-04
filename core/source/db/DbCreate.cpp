#include "../../include/Include.h"

#ifdef __WITHMYSQL__
namespace std {
	
    void DbCreate::runSelect(SqlCommand * nSqlCommand)
	{
	}
	
    void DbCreate::runWhere(SqlCommand * nSqlCommand)
	{
	}
	
    const char * DbCreate::getTableName()
	{
		return "wanmei";
	}
	
    SqlType_ DbCreate::getSqlType()
	{
		return SqlType_::mDataBase_;
	}
	
}
#endif
