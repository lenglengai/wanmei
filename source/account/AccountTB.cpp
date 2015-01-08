#include "../Include.h"

namespace std {
	
	void AccountTB::runSelect(SqlCommand * nSqlCommand)
	{
		nSqlCommand->runInt64(mAccountId, "accountId"); 
		nSqlCommand->runString(mAccountName, "accountName");
	#ifdef __SERVER__
		nSqlCommand->runInt32(mPassward, "passward");
		nSqlCommand->runInt32(mAllRenminbi, "allRenminbi");
		nSqlCommand->runInt32(mMoneyTime, "moneyTime");
		nSqlCommand->runInt32(mMoneyCount, "moneyCount");
		nSqlCommand->runInt32(mRenminbi, "renminbi");
		nSqlCommand->runInt32(mCreateTime, "createTime");
		nSqlCommand->runInt32(mActiviteTime, "activiteTime");
		nSqlCommand->runInt32(mPermission, "permission");
		nSqlCommand->runInt32(mLoginType, "loginType");
		nSqlCommand->runString(mProvider, "provider");
	#endif
	#ifdef __CLIENT__
		nSqlCommand->runInt32(accountNo, "accountNo");
		nSqlCommand->runString(passward, "passward");
	#endif
	}
	
    void AccountTB::runWhere(SqlCommand * nSqlCommand)
	{
	}
	
    const char * AccountTB::getTableName() const
	{
		return "t_account";
	}
	
    SqlType_ AccountTB::getSqlType() const
	{
		return SqlType_::mCreateTB_;
	}
	
	void AccountTB::runClear()
	{
		mAccountId = 0;
		mAccountName = "";
	#ifdef __SERVER__
		mPassward = 0;
		mAllRenminbi = 0;
		mMoneyTime = 0;
		mMoneyCount = 0;
		mRenminbi = 0;
		mCreateTime = 0;
		mActiviteTime = 0;
		mPermission = 0;
		mLoginType = 0;
		mProvider = "";
	#endif
	#ifdef __CLIENT__
		mAccountNo = 0;
		mPassward = "";
	#endif
	}
	
	AccountTB::AccountTB()
	{
		this->runClear();
	}
	
	AccountTB::~AccountTB()
	{
		this->runClear();
	}
	
}
