#include "../../include/Include.h"

namespace std {

	void IDataBase::recycleConnection(DbConnectionPtr& nDbConnection)
	{
		std::lock_guard<std::mutex> lock_(mMutex);
		nDbConnection->runRecycle();
	}
	
	DbConnectionPtr& IDataBase::getConnection()
	{
		std::lock_guard<std::mutex> lock_(mMutex);
		for (auto& it : mDbConnections) {
			if ( it->runGet()) {
				return it;
			}
		}
		__i32 connectionCount_ = static_cast<__i32>(mDbConnections.size());
		if (connectionCount_ < mMaxConnections) {
			DbConnectionPtr dbConnection_ = this->createConnection();
			dbConnection_->runGet();
			mDbConnections.push_back(dbConnection_);
			return mDbConnections.back();
		} else {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(connectionCount_));
			return __defaultptr<IDbConnection>();
		}
	}
	
	__i32 IDataBase::getMaxUsedSeconds()
	{
		return mMaxUsedSeconds;
	}
	
	const char * IDataBase::streamName()
	{
		return "dataBase";
	}
	
	const char * IDataBase::streamUrl()
	{
		return "dataBase.xml"
	}
	
	std::string& IDataBase::getHostName()
	{
		return mHostName;
	}
	
	std::string& IDataBase::getUserName()
	{
		return mUserName;
	}
	
	std::string& IDataBase::getPassword()
	{
		return mPassword;
	}
	
	std::string& IDataBase::getDbName()
	{
		return mDbName;
	}
	
	__i32 IDataBase::getPort()
	{
		return mPort;
	}
	
	void IDataBase::runClear()
	{
		mMaxConnections = 100;
		mMaxUsedHours = 10;
		
		mHostName = "127.0.0.1";
		mUserName = "root";
		mPassword = "";
		mDbName = "wanmei";
		mPort = 3306;
		
		std::lock_guard<std::mutex> lock_(mMutex);
		for (auto& it : mDbConnections) {
			it->runDisconnect();
		}
		mDbConnections.clear();
	}
	
	IDataBase::IDataBase()
	{
		this->runClear();
	}
	
	IDataBase::~IDataBase()
	{
		this->runClear();
	}
	
}
