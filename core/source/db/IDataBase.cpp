#include "../../include/Include.h"

namespace std {

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
