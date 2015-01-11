#include "../Include.h"

#include "MySqlDataBase.h"
#include "SqliteDataBase.h"

#ifdef __WITHSQL__
namespace std {
	
#ifdef __CONSOLE__
	const StringWriterPtr DbService::commandInfo(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		string className_(""); 
		__i32 classid_ = __classinfo<DbService>(className_);
		stringWriter_->runString(className_, "className");
		stringWriter_->runInt32(classid_, "classId");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
	
	const StringWriterPtr DbService::commandRunSql(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		const string& strValue_ = nCommandArgs.getCommandArg(1);
		__i16 result_ = this->runSql(strValue_.c_str());
		stringWriter_->runInt16(result_, "result");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
	
#ifdef __SERVER__
	const StringWriterPtr DbService::commandRunLogSql(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		const string& strValue_ = nCommandArgs.getCommandArg(1);
		__i16 result_ = this->runLogSql(strValue_.c_str());
		stringWriter_->runInt16(result_, "result");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}

	const StringWriterPtr DbService::commandRunLoginSql(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		const string& strValue_ = nCommandArgs.getCommandArg(1);
		__i16 result_ = this->runLoginSql(strValue_.c_str());
		stringWriter_->runInt16(result_, "result");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
#endif
#endif

	__i16 DbService::runSql(ISqlHeadstream * nSqlHeadstream)
	{
		return mGameDb->runSql(nSqlHeadstream);
	}
	
	__i16 DbService::runSql(const char * nSql)
	{
		return mGameDb->runSql(nSql);
	}
	
#ifdef __SERVER__
	__i16 DbService::runLoginSql(ISqlHeadstream * nSqlHeadstream)
	{
		return mLoginDb->runSql(nSqlHeadstream);
	}
	
	__i16 DbService::runLoginSql(const char * nSql)
	{
		return mLoginDb->runSql(nSql);
	}
	
	__i16 DbService::runLogSql(ISqlHeadstream * nSqlHeadstream)
	{
		return mLogDb->runSql(nSqlHeadstream);
	}
	
	__i16 DbService::runLogSql(const char * nSql)
	{
		return mLogDb->runSql(nSql);
	}
#endif

	bool DbService::runPreinit()
	{
	#ifdef __CONSOLE__
		this->registerCommand("info", std::bind(&DbService::commandInfo, this, placeholders::_1));
		this->registerCommand("runSql", std::bind(&DbService::commandRunSql, this, placeholders::_1));
	#ifdef __SERVER__
		this->registerCommand("runLogSql", std::bind(&DbService::commandRunLogSql, this, placeholders::_1));
		this->registerCommand("runLoginSql", std::bind(&DbService::commandRunLoginSql, this, placeholders::_1));
	#endif
	#endif
		return true;
	}
	
	void DbService::runConfig()
	{
	#if defined(__SERVER__) &&  defined(__WITHMYSQL__)
		mGameDb.reset(new MySqlDataBase());
		mGameDb->setStreamUrl("gameDb.xml");
		mGameDb->runLoad();
		
		mLoginDb.reset(new MySqlDataBase());
		mLoginDb->setStreamUrl("loginDb.xml");
		mLoginDb->runLoad();
		
		mLogDb.reset(new MySqlDataBase());
		mLogDb->setStreamUrl("logDb.xml");
		mLogDb->runLoad();
	#endif
	}
	
	void DbService::runInitDb()
	{
	#if defined(__CLIENT__) &&  defined(__WITHSQLITE__)
		mGameDb.reset(new SqliteDataBase());
		if ( mGameDb->needCreate() ) {
			if ( mGameDb->runCreate() ) {
				InitService& initService_ = Singleton<InitService>::instance();
				initService_.runInitTable();
			}
		} else {
			mGameDb->runOpen();
		}
	#endif
	#if defined(__SERVER__) &&  defined(__WITHMYSQL__)
		mGameDb.reset(new SqliteDataBase());
		if ( mGameDb->needCreate() ) {
			if ( mGameDb->runCreate() ) {
				InitService& initService_ = Singleton<InitService>::instance();
				initService_.runInitTable();
			}
		} else {
			mGameDb->runOpen();
		}
	#endif
	}
	
	void DbService::stopEnd()
	{
		mGameDb->runClose();
	#ifdef __SERVER__
		mLoginDb->runClose();
		mLogDb->runClose();
	#endif
	}
	
	DbService::DbService()
	{
	}
	
	DbService::~DbService()
	{
	}
	
	static Service<DbService> sDbService;
	
}
#endif
