#pragma once

#include "MySqlConnection.h"

#ifdef __WITHMYSQL__
namespace std {

	class MySqlDataBase : public IDataBase
	{
	public:
		__i16 runSql(ISqlHeadstream * nSqlHeadstream);
		__i16 runSql(const char * nSql);
		void runLoad();
		
	private:
		void recycleConnection(MySqlConnectionPtr& nMySqlConnection);
		MySqlConnectionPtr& getConnection();
		
	public:
		MySqlDataBase();
		~MySqlDataBase();
	
	private:
		list<MySqlConnectionPtr> mMySqlConnections;
		mutex mMutex;
	};
	
}
#endif
