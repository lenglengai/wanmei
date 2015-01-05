#include "../Include.h"

#ifdef __WITHSQL__
namespace std {

#ifdef __WITHMYSQL__
	void IDataBase::runLoad()
	{
		ArchiveService& archiveService_ = Singleton<ArchiveService>::instance();
		archiveService_.xmlStream(this);
	}
	
	__i32 IDataBase::getMaxUsedSeconds() const
	{
		return mMaxUsedSeconds;
	}
	
	const char * IDataBase::streamName() const
	{
		return "dataBase";
	}
	
	void IDataBase::setStreamUrl(const char * nStreamUrl)
	{
		mStreamUrl = nStreamUrl;
	}
	
	const char * IDataBase::streamUrl() const
	{
		return mStreamUrl.c_str();
	}
	
	const std::string& IDataBase::getHostName() const
	{
		return mHostName;
	}
	
	const std::string& IDataBase::getUserName() const
	{
		return mUserName;
	}
	
	const std::string& IDataBase::getPassword() const
	{
		return mPassword;
	}
	
	__i32 IDataBase::getPort() const
	{
		return mPort;
	}
#endif

	void IDataBase::setDbName(const char * nDbName)
	{
		mDbName = nDbName;
	}
	
	const std::string& IDataBase::getDbName() const
	{
		return mDbName;
	}
	
	void IDataBase::runClear()
	{
	#ifdef __WITHMYSQL__
		mMaxConnections = 100;
		mMaxUsedSeconds = 10;
		
		mHostName = "127.0.0.1";
		mUserName = "root";
		mPassword = "";
		mPort = 3306;
		
		mStreamUrl = "";
	#endif
		mDbName = "gameDb";
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
