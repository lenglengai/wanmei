#include "../Include.h"

#ifdef __WITHMYSQL__
namespace std {
	
    void DbSet::runSelect(SqlCommand * nSqlCommand)
	{
	}
	
    void DbSet::runWhere(SqlCommand * nSqlCommand)
	{
	}
	
    const char * DbSet::getTableName()
	{
		return "wanmei";
	}
	
    SqlType_ DbSet::getSqlType()
	{
		return SqlType_::mSetDB_;
	}
	
}
#endif
