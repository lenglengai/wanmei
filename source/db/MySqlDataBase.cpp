#include "../Include.h"

#ifdef __WITHMYSQL__
namespace std {

	__i16 MySqlDataBase::runSql(ISqlHeadstream * nSqlHeadstream)
	{
		MySqlConnectionPtr& mySqlConnection_ = this->getConnection();
		if (!mySqlConnection_) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1("!mySqlConnection_"));
			return Error_::mDbError_;
		}
		__i16 result_ = mySqlConnection_->runSql(nSqlHeadstream);
		this->recycleConnection(mySqlConnection_);
		return result_;
	}
	
	__i16 MySqlDataBase::runSql(const char * nSql)
	{
		MySqlConnectionPtr& mySqlConnection_ = this->getConnection();
		if (!mySqlConnection_) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1("!mySqlConnection_"));
			return Error_::mDbError_;
		}
		__i16 result_ = mySqlConnection_->runSql(nSql);
		this->recycleConnection(mySqlConnection_);
		return result_;
	}
	
	void MySqlDataBase::recycleConnection(MySqlConnectionPtr& nMySqlConnection)
	{
		std::lock_guard<std::mutex> lock_(mMutex);
		nMySqlConnection->runRecycle();
	}
	
	MySqlConnectionPtr& MySqlDataBase::getConnection()
	{
		std::lock_guard<std::mutex> lock_(mMutex);
		for (auto& it : mMySqlConnections) {
			if ( it->runGet()) {
				return it;
			}
		}
		__i32 connectionCount_ = static_cast<__i32>(mMySqlConnections.size());
		if (connectionCount_ < mMaxConnections) {
			MySqlConnectionPtr mySqlConnection_(new MySqlConnection(this));
			mySqlConnection_->runGet();
			mMySqlConnections.push_back(mySqlConnection_);
			return mMySqlConnections.back();
		} else {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(connectionCount_));
			return __defaultptr<MySqlConnection>();
		}
	}
	
	void MySqlDataBase::runLoad()
	{
		ArchiveService& archiveService_ = Singleton<ArchiveService>::instance();
		archiveService_.xmlStream(this);
	}
	
	MySqlDataBase::MySqlDataBase()
	{
		mMySqlConnections.clear();
	}
	
	MySqlDataBase::~MySqlDataBase()
	{
		std::lock_guard<std::mutex> lock_(mMutex);
		for (auto& it : mMySqlConnections) {
			it->runDisconnect();
		}
		mMySqlConnections.clear();
	}
	
}
#endif
