#pragma once

namespace std {

    class ISqlHeadstream
    {
	public:
        virtual void runSelect(SqlCommand nSqlCommand) = 0;
        virtual void runWhere(ISqlCommand nSqlCommand) = 0;
        virtual const char * getTableName() = 0;
        virtual SqlType_ getSqlType() = 0;
    }
}
