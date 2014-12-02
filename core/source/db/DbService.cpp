#include "../../include/Include.h"

#ifdef __WITHMYSQL__
namespace std {
	
	__i16 DbService::runSql(ISqlHeadstream * nSqlHeadstream)
	{
		return mDataBase->runSql(nSqlHeadstream);
	}
	
	bool DbService::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunStart0.connect(boost::bind(&DbService::runStart, this));

		ArchiveService& archiveService_ = Singleton<ArchiveService>::instance();
		archiveService_.m_tRunConfigure.connect(boost::bind(&DbService::runLoad, this));
		
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
		
		return true;
	}
	
	void DbService::runLoad()
	{
		mDataBase.reset(new MySqlDataBase());
		mDataBase->runLoad();
		
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}

	void DbService::runStart()
	{
		DataBaseCreate dataBaseCreate;
		mDataBase->runSql(&dataBaseCreate);
		
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}
	
	DbService::DbService()
	{
	}
	
	DbService::~DbService()
	{
	}
	
	static Preinit<DbService> sDbServicePreinit;
	
}
#endif
