#pragma once

namespace std {

	class IDataBase : boost::noncopyable
	{
	public:
		void recycleConnection(DbConnectionPtr& nDbConnection);
		DbConnectionPtr& getConnection();
		
		template<class T>
		void headSerialize(T& nSerialize)
		{
			nSerialize.runString(mHostName, "hostName");
			nSerialize.runString(mUserName, "userName");
			nSerialize.runString(mPassword, "password");
			nSerialize.runString(mDbName, "dbName");
			nSerialize.runInt32(mPort, "port");
			nSerialize.runInt32(mMaxConnections, "maxConnections");
			nSerialize.runInt32(mMaxUsedSeconds, "maxUsedSeconds");
		}
		
		const char * streamName();
		const char * streamUrl();
		
		std::string& getHostName();
		std::string& getUserName();
		std::string& getPassword();
		std::string& getDbName();
		__i32 getPort();
		
		__i32 getMaxUsedSeconds();
		
	protected:
		virtual DbConnectionPtr createConnection() = 0;
		
	private:
		void runClear();
		
	public:
		IDataBase();
		virtual ~IDataBase();
		
	private:
		std::string mHostName;
		std::string mUserName;
		std::string mPassword;
		std::string mDbName;
		__i32 mPort;
		__i32 mMaxConnections;
		__i32 mMaxUsedSeconds;
		std::list<DbConnectionPtr> mDbConnections;
		std::mutex mMutex;
	};
	typedef std::shared_ptr<IDataBase> DataBasePtr;
	
}
