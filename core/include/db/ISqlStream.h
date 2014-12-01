#pragma once

namespace std {

	class SqlCommand;
    class ISqlStream
    {
	public:
        virtual void runSelect(SqlCommand * nSqlCommand) = 0;
        virtual void runWhen(SqlCommand * nSqlCommand) = 0;
    };
	
}
