#pragma once

#ifdef __WITHSQLITE__

#include "../../dependence/sqlite/sqlite3.h"

namespace std {

	class SqliteQuery : public IDbQuery
	{
	public:
		void getValue(string& nValue);
		__i16 runQuery();
		bool nextRow();
		
		SqliteQuery(sqlite3 * nSqlite, sqlite3_stmt * nStatement);
		~SqliteQuery();
	
	private:
		sqlite3_stmt * mStatement;
		sqlite3 * mSqlite;
		__i32 * mLengths;
		__i8 mIndex;
	};
	
}
#endif
