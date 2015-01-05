#pragma once

#ifdef __WITHMYSQL__
namespace std {

	class SqliteDataBase : public IDataBase
	{
	public:
		__i16 runSql(ISqlHeadstream * nSqlHeadstream);
		__i16 runSql(const char * nSql);
		void runOpen();
		void runClose();
		
	public:
		SqliteDataBase();
		~SqliteDataBase();
		
	private:
		sqlite3 * mSqlite;
		char * mErrorMsg;
		bool mIsClosed;
	};
	
}
#endif
