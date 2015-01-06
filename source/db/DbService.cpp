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

	const StringWriterPtr DbService::commandCreateDb(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		DataBasePtr database_(new MySqlDataBase());
		const string& streamUrl_ = nCommandArgs.getCommandArg(1);
		database_->setStreamUrl(streamUrl_.c_str());
		database_->runLoad();
		string dropDb_("DROP DATABASE IF EXISTS ");
		dropDb_ += database_->getDbName(); 
		dropDb_ += ";";
		string createDb_("CREATE DATABASE ");
		createDb_ += database_->getDbName(); 
		createDb_ += ";";
		database_->setDbName("");
		__i16 result_ = database_->runSql(dropDb_.c_str());
		stringWriter_->runInt16(result_, "result0");
		result_ = database_->runSql(createDb_.c_str());
		stringWriter_->runInt16(result_, "result1");
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
	
#ifdef __WITHMYSQL__
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
	#ifdef __WITHMYSQL__
		this->registerCommand("runLogSql", std::bind(&DbService::commandRunLogSql, this, placeholders::_1));
		this->registerCommand("runLoginSql", std::bind(&DbService::commandRunLoginSql, this, placeholders::_1));
		this->registerCommand("createDb", std::bind(&DbService::commandCreateDb, this, placeholders::_1));
	#endif
	#endif
		return true;
	}
	
	void DbService::runConfig()
	{
	#ifdef __WITHMYSQL__
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
	#ifdef __WITHSQLITE__
		mGameDb.reset(new SqliteDataBase());
		mGameDb->runOpen();
	#endif
	]
	
	void DbService::stopEnd()
	{
	#ifdef __WITHSQLITE__
		mGameDb->runClose();
	#endif
	]
	
	DbService::DbService()
	{
	}
	
	DbService::~DbService()
	{
	}
	
	static Service<DbService> sDbService;
	
}
#endif
