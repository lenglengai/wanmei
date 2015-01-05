#pragma once

#ifdef __WITHSQL__
namespace std {

	class SqlCommand;
    class ISqlStream
    {
	public:
        virtual void runSelect(SqlCommand * nSqlCommand) = 0;
    };
	
}
#endif
