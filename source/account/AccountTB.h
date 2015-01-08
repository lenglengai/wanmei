#pragma once

namespace std {
	
	class AccountTB : public ISqlHeadstream
	{
	public:
	    void runSelect(SqlCommand * nSqlCommand) OVERRIDE FINAL;
        void runWhere(SqlCommand * nSqlCommand) OVERRIDE FINAL;
        const char * getTableName() const OVERRIDE FINAL;
        SqlType_ getSqlType() const OVERRIDE FINAL;
		
	private:
		void runClear();
		
	public:	
		AccountTB();
		~AccountTB();
		
	private:
		__i64 mAccountId;
		string mAccountName;
	#ifdef __SERVER__
		__i32 mPassward;
		__i32 mAllRenminbi;
		__i32 mMoneyTime;
		__i32 mMoneyCount;
		__i32 mRenminbi;
		__i32 mCreateTime;
		__i32 mActiviteTime;
		__i32 mPermission;
		__i32 mLoginType;
		string mProvider;
	#endif
	#ifdef __CLIENT__
		__i32 mAccountNo;
		string mPassward;
	#endif
	};
	typedef shared_ptr<AccountTB> AccountTBPtr;
	typedef weak_ptr<AccountTB> AccountTBWtr;
	
}
