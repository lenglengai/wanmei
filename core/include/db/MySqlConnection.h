#pragma once

#include <mysql.h>

namespace std {
	
	class MySqlConnection : public IDbConnection
	{
	public:
		__i16 runSql(ISqlHeadstream * nSqlHeadstream);
	protected:
		void internalConnect();
		void internalDisconnect();
	
	public:
		explicit MySqlConnection(IDataBase * nDataBase);
		~MySqlConnection();
		
	private:
		MYSQL mMYSQL;
	};
	
}
