#pragma once

#ifdef __WITHSQLITE__

#include "../../dependence/sqlite/sqlite3.h"

namespace std {

	class SqliteQuery : public IDbQuery
	{
	public:
		void runBool(bool& nValue) OVERRIDE FINAL;
		void runInt8(__i8& nValue) OVERRIDE FINAL;
		void runInt16(__i16& nValue) OVERRIDE FINAL;
		void runInt32(__i32& nValue) OVERRIDE FINAL;
		void runInt64(__i64& nValue) OVERRIDE FINAL;
		void runFloat(float& nValue) OVERRIDE FINAL;
		void runDouble(double& nValue) OVERRIDE FINAL;
		void runString(string& nValue) OVERRIDE FINAL;
		void runData(char *& nValue, __i16& nSize) OVERRIDE FINAL;
		
		bool nextRow() OVERRIDE FINAL;
		
		SqliteQuery(sqlite3_stmt * nStatement, sqlite3 * nSqlite);
		~SqliteQuery();
	
	private:
		sqlite3_stmt * mStatement;
		sqlite3 * mSqlite;
		__i8 mIndex;
	};
	
}
#endif
