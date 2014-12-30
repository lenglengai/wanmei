#pragma once

#ifdef __WITHMYSQL__
namespace std {

	class MySqlDataBase : public IDataBase
	{
	public:
		__i16 runSql(ISqlHeadstream * nSqlHeadstream);
		void runLoad();
	private:
		void recycleConnection(MySqlConnectionPtr& nMySqlConnection);
		MySqlConnectionPtr& getConnection();
		
	public:
		MySqlDataBase();
		~MySqlDataBase();
	
	private:
		std::list<MySqlConnectionPtr> mMySqlConnections;
		std::mutex mMutex;
	};
	
}
#endif
