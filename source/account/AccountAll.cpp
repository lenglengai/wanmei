#include "../Include.h"
#include "AccountAll.h"

namespace std {

#ifdef __CONSOLE__
	void AccountAll::runStringWriter(StringWriterPtr& nStringWriter) const
	{
		nStringWriter->startClass("accountAll");
		nStringWriter->runInt32(mMoneyTime, "moneyTime");
		nStringWriter->runInt32(mMoneyCount, "moneyCount");
		nStringWriter->runInt32(mRenminbi, "renminbi");
	#ifdef __CLIENT__
		nStringWriter->runString(mPassward, "passward");
	#endif
	#ifdef __SERVER__
		nStringWriter->runInt64(mPassward, "passward");
	#endif
		Account::runStringWriter(nStringWriter);
		nStringWriter->finishClass();
	}
#endif
	
	void AccountAll::setMoneyTime(const __i32 nMoneyTime)
	{
		mMoneyTime = nMoneyTime;
	}
	
	__i32 AccountAll::getMoneyTime() const
	{
		return mMoneyTime;
	}
	
	void AccountAll::setMoneyCount(const __i32 nMoneyCount)
	{
		mMoneyCount = nMoneyCount;
	}
	
	__i32 AccountAll::getMoneyCount() const
	{
		return mMoneyCount;
	}
	
	void AccountAll::setRenminbi(const __i32 nRenminbi)
	{
		nRenminbi = nRenminbi;
	}
	
	__i32 AccountAll::getRenminbi() const
	{
		return nRenminbi;
	}
	
#ifdef __CLIENT__
	void AccountAll::setPassward(const char * nPassward)
	{
		mPassward = nPassward;
	}
	
	const string& AccountAll::getPassward() const
	{
		return mPassward;
	}
#endif

#ifdef __SERVER__
	void AccountAll::setPassward(const __i64 nPassward)
	{
		mPassward = nPassward;
	}
	
	__i64 AccountAll::getPassward() const
	{
		return mPassward;
	}
#endif

	AccountAll::AccountAll()
		: mMoneyTime (0)
		, mMoneyCount ("")
		, mRenminbi (0)
	#ifdef __CLIENT__
		, mPassward ("")
	#endif
	#ifdef __SERVER__
		, mPassward (0)
	#endif
	{
	}
	
	AccountAll::~AccountAll()
	{
		mMoneyTime = 0;
		mMoneyCount = "";
		mRenminbi = 0;
	#ifdef __CLIENT__
		mPassward = "";
	#endif
	#ifdef __SERVER__
		mPassward = 0;
	#endif
	}

}
