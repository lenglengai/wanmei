#pragma once

#ifdef __WITHSQL__
namespace std {

    class ISqlHeadstream : noncopyable
    {
	public:
        virtual void runSelect(SqlCommand * nSqlCommand) = 0;
        virtual void runWhere(SqlCommand * nSqlCommand) = 0;
        virtual const char * getTableName() const = 0;
        virtual SqlType_ getSqlType() const = 0;
    };
	
}
#endif
