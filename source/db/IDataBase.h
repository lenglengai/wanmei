#pragma once

#include "ISqlHeadstream.h"

#ifdef __WITHSQL__
namespace std {

	class IDataBase : noncopyable
	{
	public:
		virtual __i16 runSql(ISqlHeadstream * nSqlHeadstream) = 0;
		virtual __i16 runSql(const char * nSql) = 0;
		
	#ifdef __WITHMYSQL__
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
		
		const string& getHostName() const;
		const string& getUserName() const;
		const string& getPassword() const;
		__i32 getPort() const;
		
		__i32 getMaxUsedSeconds() const;
	#endif
		void setDbName(const char * nDbName);
		const string& getDbName() const;
		
	#ifdef __WITHSQLITE__
		virtual bool runOpen() = 0;
		virtual void runClose() = 0;
	#endif
	
	private:
		void runClear();
		
	public:
		IDataBase();
		virtual ~IDataBase();
		
	protected:
	#ifdef __WITHMYSQL__
		string mHostName;
		string mUserName;
		string mPassword;
		string mStreamUrl;
		__i32 mPort;
		__i32 mMaxConnections;
		__i32 mMaxUsedSeconds;
	#endif
		string mDbName;
	};
	typedef shared_ptr<IDataBase> DataBasePtr;
	
}
#endif
