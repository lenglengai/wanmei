#pragma once

#include "SqlCommand.h"

#ifdef __WITHSQL__
namespace std {

    class ISqlStream : noncopyable
    {
	public:
        virtual void runSelect(SqlCommand * nSqlCommand) = 0;
    };
	
}
#endif
