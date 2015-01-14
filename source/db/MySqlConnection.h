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
		bool runConnect();
		bool runCreate();
		void runDisconnect();
		
	private:
		void runActivate(bool nForce = false);
		
		bool internalConnect();
		bool internalCreate();
		void internalDisconnect();
	
	public:
		explicit MySqlConnection(IDataBase * nDataBase);
		~MySqlConnection();
		
	private:
		IDataBase * mDataBase;
		__i32 mTimeStamp;
		bool mConnected;
		bool mBusy;
		
		MYSQL mMYSQL;
	};
	typedef shared_ptr<MySqlConnection> MySqlConnectionPtr;
	
}
#endif
