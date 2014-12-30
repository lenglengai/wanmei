#pragma once

#ifdef __WITHMYSQL__
namespace std {
	
	class MySqlConnection : boost::noncopyable
	{
	public:
		__i16 runSql(ISqlHeadstream * nSqlHeadstream);
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
	typedef std::shared_ptr<MySqlConnection> MySqlConnectionPtr;
	
}
#endif
