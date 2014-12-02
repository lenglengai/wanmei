#pragma once

#ifdef __WITHMYSQL__
namespace std {

	class SqlCommand;
    class ISqlHeadstream
    {
	public:
        virtual void runSelect(SqlCommand * nSqlCommand) = 0;
        virtual void runWhere(SqlCommand * nSqlCommand) = 0;
        virtual const char * getTableName() = 0;
        virtual SqlType_ getSqlType() = 0;
    };
	
}
#endif
