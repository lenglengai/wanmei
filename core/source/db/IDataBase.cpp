#include "../../include/Include.h"

#ifdef __WITHMYSQL__
namespace std {

	void IDataBase::runLoad()
	{
		ArchiveService& archiveService_ = Singleton<ArchiveService>::instance();
		archiveService_.xmlUrlStream(this);

		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
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
		return "dataBase.xml";
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
	
	void IDataBase::setDbName(const char * nDbName)
	{
		mDbName = nDbName;
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
		mMaxUsedSeconds = 10;
		
		mHostName = "127.0.0.1";
		mUserName = "root";
		mPassword = "";
		mDbName = "wanmei";
		mPort = 3306;
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
#endif
