#include "../Include.h"

#ifdef __WITHSQLITE__
namespace std {

	void SqliteQuery::runBool(bool& nValue)
	{
		int value_ = sqlite3_column_int(mStatement, mIndex);
		nValue = ( (1 == value_) ? true : false );
		++mIndex;
	}
	
	void SqliteQuery::runInt8(__i8& nValue)
	{
		nValue = sqlite3_column_int(mStatement, mIndex);
		++mIndex;
	}
	
	void SqliteQuery::runInt16(__i16& nValue)
	{
		nValue = sqlite3_column_int(mStatement, mIndex);
		++mIndex;
	}
	
	void SqliteQuery::runInt32(__i32& nValue)
	{
		nValue = sqlite3_column_int(mStatement, mIndex);
		++mIndex;
	}
	
	void SqliteQuery::runInt64(__i64& nValue)
	{
		nValue = sqlite3_column_int64(mStatement, mIndex);
		++mIndex;
	}
	
	void SqliteQuery::runFloat(float& nValue)
	{
		nValue = sqlite3_column_double(mStatement, mIndex);
		++mIndex;
	}
	
	void SqliteQuery::runDouble(double& nValue)
	{
		nValue = sqlite3_column_double(mStatement, mIndex);
		++mIndex;
	}
	
	void SqliteQuery::runString(string& nValue)
	{
		nValue = static_cast<const char *>(sqlite3_column_text(mStatement, mIndex));
		++mIndex;
	}
	
	void SqliteQuery::runData(char *& nValue, __i16& nSize)
	{
		nSize = sqlite3_column_bytes(mStatement, mIndex);
		const void * value_ = sqlite3_column_blob(mStatement, mIndex);
		nValue = new char[nSize];
		memcpy(nValue, value_, nSize);
		++mIndex;
	}

	bool SqliteQuery::nextRow()
	{
		return true;
	}
		
	SqliteQuery::SqliteQuery(sqlite3 * nSqlite, sqlite3_stmt * nStatement)
		: mStatement (nStatement)
		, mSqlite(nSqlite)
		, mIndex(0)
	{
	}
	
	SqliteQuery::~SqliteQuery()
	{
		sqlite3_finalize(mStatement);
	}
	
}
#endif
