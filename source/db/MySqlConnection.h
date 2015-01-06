#pragma once

#ifdef __WITHMYSQL__

#include "MySqlQuery.h"

namespace std {
	
	class MySqlConnection : noncopyable
	{
	public:
		__i16 runSql(ISqlHeadstream * nSqlHeadstream);
		__i16 runSql(const char * nSql);
		void runRecycle();
		bool runGet();
		void runDisconnect();
		
	private:
		void runActivate(bool nForce = false);
		void runConnect();
		
		void internalConnect();
		void internalDisconnect();
	
	public:
		explicit MySqlConnection(IDataBase * nDataBase);
		~MySqlConnection();
		
	private:
		IDataBase * mDataBase;
		__i64 mTimeStamp;
		bool mConnected;
		bool mBusy;
		
		MYSQL mMYSQL;
	};
	typedef shared_ptr<MySqlConnection> MySqlConnectionPtr;
	
}
#endif
