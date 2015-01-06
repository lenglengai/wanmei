#include "../Include.h"
#include "SqliteDataBase.h"

#ifdef __WITHMYSQL__
namespace std {

	__i16 SqliteDataBase::runSql(ISqlHeadstream * nSqlHeadstream)
	{
		SqlCommand sqlCommand;
		sqlCommand.runHeadstream(nSqlHeadstream);
		const std::string& strSql = sqlCommand.getValue();
		if ( SqlType_::mSelect_ != nSqlHeadstream->getSqlType() ) {
			return this->runSql(strSql.c_str());
		}
		const char * tail_ = "";
		sqlite3_stmt * statement_ = nullptr;
		int errorCode_ = sqlite3_prepare_v2(mSqlite, strSql.c_str(), -1, &statement_, &tail_);
		if (SQLITE_OK != errorCode_) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(sqlite3_errmsg(mSqlite)));
			return Error_::mDbError_;
		}
		errorCode_ = sqlite3_step(statement_);
		if (SQLITE_DONE == errorCode_) {
			return Error_::mSucess_;
		} else if (SQLITE_ROW == errorCode_) {
			SqliteQuery sqliteQuery_(mSqlite, statement_);
			sqlCommand.runQuery(nSqlHeadstream, &sqliteQuery_);
			return Error_::mSucess_;
		} else {
			errorCode_ = sqlite3_finalize(statement_);
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(sqlite3_errmsg(mSqlite)));
			return Error_::mDbError_;
		}
	}
	
	__i16 SqliteDataBase::runSql(const char * nSql)
	{
		int errorCode_ = sqlite3_exec(mSqlite, nSql, 0, 0, &mErrorMsg);
		if (SQLITE_OK != errorCode_) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(mErrorMsg));
			return Error_::mDbError_;
		}
		sqlite3_changes(mSqlite);
		return Error_::mSucess_;
	}

	void SqliteDataBase::runOpen()
	{
		int errorCode_ = sqlite3_open(mDbName.c_str(), &mSqlite);
		if(SQLITE_OK != errorCode_) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(sqlite3_errmsg(mSqlite)));
			sqlite3_close(mSqlite);
			return;
		}
		mIsClosed = false;
	}
	
	void SqliteDataBase::runClose()
	{
		if (mIsClosed) return;
		int errorCode_ = sqlite3_close(mSqlite);
		if(SQLITE_OK != errorCode_) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(sqlite3_errmsg(mSqlite)));
		}
	}
	
	SqliteDataBase::SqliteDataBase()
	{
	}
	
	SqliteDataBase::~SqliteDataBase()
	{
	}
	
}
#endif
