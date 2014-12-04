#pragma once

#ifdef __WITHMYSQL__
namespace std {

	class IDataBase : boost::noncopyable
	{
	public:
		virtual __i16 runSql(ISqlHeadstream * nSqlHeadstream) = 0;
		
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
		void runLoad();
		
		void setDbName(const char * nDbName);
		std::string& getHostName();
		std::string& getUserName();
		std::string& getPassword();
		std::string& getDbName();
		__i32 getPort();
		
		__i32 getMaxUsedSeconds();
		
	private:
		void runClear();
		
	public:
		IDataBase();
		virtual ~IDataBase();
		
	protected:
		std::string mHostName;
		std::string mUserName;
		std::string mPassword;
		std::string mDbName;
		__i32 mPort;
		__i32 mMaxConnections;
		__i32 mMaxUsedSeconds;
	};
	typedef std::shared_ptr<IDataBase> DataBasePtr;
	
}
#endif
