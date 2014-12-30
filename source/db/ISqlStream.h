#pragma once

#ifdef __WITHMYSQL__
namespace std {

	class SqlCommand;
    class ISqlStream
    {
	public:
        virtual void runSelect(SqlCommand * nSqlCommand) = 0;
    };
	
}
#endif
