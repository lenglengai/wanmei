#pragma once

namespace std {

	class MySqlDataBase : public IDataBase
	{
	protected:
		void runSql(ISqlHeadstream * nSqlHeadstream);
		DbConnectionPtr createConnection();
		
		void recycleConnection(DbConnectionPtr& nDbConnection);
		DbConnectionPtr& getConnection();
		
		virtual DbConnectionPtr createConnection() = 0;
		
	public:
		MySqlDataBase();
		~MySqlDataBase();
	
	private:
		std::list<DbConnectionPtr> mDbConnections;
		std::mutex mMutex;
	};
	
}
