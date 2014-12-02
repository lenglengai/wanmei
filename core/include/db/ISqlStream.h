#pragma once

namespace std {

	class SqlCommand;
    class ISqlStream
    {
	public:
        virtual void runSelect(SqlCommand * nSqlCommand) = 0;
    };
	
}
