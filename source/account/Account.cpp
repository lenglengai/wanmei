#include "../Include.h"

namespace std {

	void Account::runSelect(SqlCommand * nSqlCommand)
	{
		nSqlCommand->runString(mAccountName, "accountName", 6);
	#ifdef __SERVER__
		nSqlCommand->runInt64(mAccountId, "accountId", );
		nSqlCommand->runInt32(mAllRenminbi, "allRenminbi");
	#endif
	}
	
#ifdef __CONSOLE__
	void Account::runStringWriter(StringWriterPtr& nStringWriter) const
	{
		nStringWriter->startClass("account");
		nStringWriter->runInt32(mAllRenminbi, "allRenminbi");
		nStringWriter->runString(mAccountName, "accountName");
		nStringWriter->runInt64(mAccountId, "accountId");
		nStringWriter->finishClass();
	}
#endif
	
	void Account::setAllRenminbi(const __i32 nAllRenminbi)
	{
		mAllRenminbi = nAllRenminbi;
	}
	
	__i32 Account::getAllRenminbi() const
	{
		return mAllRenminbi;
	}
	
	void Account::setAccountName(const char * nAccountName)
	{
		mAccountName = nAccountName;
	}
	
	const string& Account::getAccountName() const
	{
		return mAccountName;
	}
	
	void Account::setAccountId(const __i64 nAccountId)
	{
		mAccountId = nAccountId;
	}
	
	__i64 Account::getAccountId() const
	{
		return mAccountId;
	}

	__i64 Account::getKey() const
	{
		return mAccountId;
	}
		
	Account::Account()
		: mAllRenminbi (0)
		, mAccountName ("")
		, mAccountId (0)
	{
	}
	
	Account::~Account()
	{
		mAllRenminbi = 0;
		mAccountName = "";
		mAccountId = 0;
	}
	
}
