#pragma once

#ifdef __WITHMYSQL__
namespace std {

	class IDataBase : noncopyable
	{
	public:
		virtual __i16 runSql(ISqlHeadstream * nSqlHeadstream) = 0;
		virtual __i16 runSql(const char * nSql) = 0;
		
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
		
		const char * streamName() const;
		void setStreamUrl(const char * nStreamUrl);
		const char * streamUrl() const;
		void runLoad();
		
		void setDbName(const char * nDbName);
		const string& getHostName() const;
		const string& getUserName() const;
		const string& getPassword() const;
		const string& getDbName() const;
		__i32 getPort() const;
		
		__i32 getMaxUsedSeconds() const;
		
	private:
		void runClear();
		
	public:
		IDataBase();
		virtual ~IDataBase();
		
	protected:
		string mHostName;
		string mUserName;
		string mPassword;
		string mDbName;
		string mStreamUrl;
		__i32 mPort;
		__i32 mMaxConnections;
		__i32 mMaxUsedSeconds;
	};
	typedef shared_ptr<IDataBase> DataBasePtr;
	
}
#endif
