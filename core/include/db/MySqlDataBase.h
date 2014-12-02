#pragma once

namespace std {

	class MySqlDataBase : public IDataBase
	{
	public:
		void runSql(ISqlHeadstream * nSqlHeadstream);
		
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
