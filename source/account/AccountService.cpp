#include "../Include.h"
#include "AccountTB.h"
#include "C2SLogin.h"
#include "S2CLogin.h"

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
	#ifdef __SERVER__
		nSqlCommand->runMapStream(mAccounts);
	#endif
	#ifdef __CLIENT__
		nSqlCommand->runStream(mAccount);
	#endif
	}
	
    void AccountService::runWhere(SqlCommand * nSqlCommand)
	{
	#ifdef __SERVER__
		TimeService& timeService_ = Service<TimeService>::instance();
		__i32 dayTime_ = timeService_.getBeforeDay(10);
		nSqlCommand->runInt32(dayTime_, "activiteTime>");
	#endif
	#ifdef __CLIENT__
		__i32 accountNo_ = 1;
		nSqlCommand->runInt32(accountNo_, "accountNo=");
	#endif
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
	
	bool AccountService::runInitTable()
	{
		AccountTB accountTB;
		DbService& dbService_ = Service<DbService>::instance();
	#ifdef __CLIENT__
		if ( Error_::mSucess_ != dbService_.runSql(&accountTB) ) {
			return false;
		}
	#endif
	#ifdef __SERVER____
		if ( Error_::mSucess_ != dbService_.runLoginSql(&accountTB) ) {
			return false;
		}
	#endif
		return true;
	}
	
	bool AccountService::loadBegin()
	{
		DbService& dbService_ = Service<DbService>::instance();
		if ( Error_::mSucess_ != dbService_.runSql(this) ) {
			return false;
		}
		return true;
	}
	
	bool AccountService::initBegin()
	{
		ProtocolService& protocolService_ = Service<ProtocolService>::instance();
		protocolService_.runRegister(this);

	#ifdef __CLIENT__
		this->addPacketId(PacketIdPtr(new PacketId<S2CLogin>()));
	#endif

	#ifdef __SERVER__
		this->addPacketId(PacketIdPtr(new PacketId<C2SLogin>()));
	#endif
		return true;
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
