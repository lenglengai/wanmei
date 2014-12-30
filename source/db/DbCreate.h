#pragma once

#ifdef __WITHMYSQL__
namespace std {

    class DbCreate : public ISqlHeadstream
    {
	public:
        void runSelect(SqlCommand * nSqlCommand);
        void runWhere(SqlCommand * nSqlCommand);
        const char * getTableName();
        SqlType_ getSqlType();
    };
	
}
#endif
