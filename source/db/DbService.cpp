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
	
#ifdef __GAME__
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
	
#ifdef __GAME__
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
	#ifdef __GAME__
		this->registerCommand("runLogSql", std::bind(&DbService::commandRunLogSql, this, placeholders::_1));
	#endif
	#endif
		return true;
	}
	
	bool DbService::runConfig()
	{
	#if defined(__GAME__) &&  defined(__WITHMYSQL__)
		mGameDb.reset(new MySqlDataBase());
		mGameDb->setStreamUrl("gameDb.xml");
		if ( !mGameDb->runLoad() ) {
			return false;
		}
		mLogDb.reset(new MySqlDataBase());
		mLogDb->setStreamUrl("logDb.xml");
		if ( !mLogDb->runLoad() ) {
			return false;
		}
	#endif
	#if defined(__LOGIN__) &&  defined(__WITHMYSQL__)
		mGameDb.reset(new MySqlDataBase());
		mGameDb->setStreamUrl("loginDb.xml");
		if ( !mGameDb->runLoad() ) {
			return false;
		}
	#endif
		return true;
	}
	
	bool DbService::runInitDb()
	{
	#if defined(__CLIENT__) &&  defined(__WITHSQLITE__)
		mGameDb.reset(new SqliteDataBase());
		if ( mGameDb->needCreate() ) {
			if ( mGameDb->runCreate() ) {
				InitService& initService_ = Singleton<InitService>::instance();
				return initService_.runInitTable();
			}
			return false;
		} else {
			return mGameDb->runOpen();
		}
	#endif
	#if defined(__SERVER__) &&  defined(__WITHMYSQL__)
		bool initTable_ = false;
		if ( mGameDb->needCreate() ) {
			if ( !mGameDb->runCreate() ) {
				return false;
			}
			initTable_ = true;
		}
	#ifdef __GAME__
		if ( mLogDb->needCreate() ) {
			if ( !mLogDb->runCreate() ) {
				return false;
			}
			initTable_ = true;
		}
	#endif
		if ( initTable_ ) {
			InitService& initService_ = Singleton<InitService>::instance();
			if ( !initService_.runInitTable() ) {
				return false;
			}
		}
	#endif
		return true;
	}
	
	void DbService::stopEnd()
	{
		mGameDb->runClose();
	#ifdef __GAME__
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
