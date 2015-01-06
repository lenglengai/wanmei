#include "../Include.h"

#include "AccountService.h"

namespace std {

#ifdef __CONSOLE__
	const StringWriterPtr AccountService::commandInfo(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		string className_(""); 
		__i32 classid_ = __classinfo<AccountService>(className_);
		stringWriter_->runString(className_, "className");
		stringWriter_->runInt32(classid_, "classId");
	#ifdef __CLIENT__
		mAccount->runStringWriter(stringWriter_);
	#endif
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
#endif
	
	void AccountService::runSelect(SqlCommand * nSqlCommand)
	{
	}
	
    void AccountService::runWhere(SqlCommand * nSqlCommand)
	{
		nSqlCommand
	}
	
    const char * AccountService::getTableName() const
	{
		return "t_account";
	}
	
    SqlType_ AccountService::getSqlType() const
	{
		return SqlType_::mSelect_;
	}
	
	bool AccountService::runPreinit()
	{
	#ifdef __CONSOLE__
		this->registerCommand("info", std::bind(&AccountService::commandInfo, this, placeholders::_1));
	#endif
		return true;
	}
	
	void AccountService::loadBegin()
	{
		DbService& dbService_ = Service<DbService>::instance();
		dbService_.runSql(this);
	}
	
	void AccountService::runClear()
	{
	#ifdef __SERVER__
		mAccounts.clear();
	#endif
	#ifdef __CLIENT__
		mAccounts.clear();
	#endif
	}
	
	AccountService::AccountService()
	{
	}
	
	AccountService::~AccountService()
	{
	}
	
	static Service<AccountService> sAccountService;

}
