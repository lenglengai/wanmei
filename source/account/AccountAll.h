#pragma once

#include "Account.h"

namespace std {
	
	class AccountAll : public Account
	{
	public:
		void runSelect(SqlCommand * nSqlCommand) OVERRIDE FINAL;
		
	#ifdef __CONSOLE__
		void runStringWriter(StringWriterPtr& nStringWriter) const;
	#endif
		void setMoneyTime(const __i32 nMoneyTime);
		__i32 getMoneyTime() const;
		void setMoneyCount(const __i32 nMoneyCount);
		__i32 getMoneyCount() const;
		void setRenminbi(const __i32 nRenminbi);
		__i32 getRenminbi() const;
	#ifdef __CLIENT__
		void setPassward(const char * nPassward);
		const string& getPassward() const;
	#endif
	#ifdef __SERVER__
		void setPassward(const __i32 nPassward);
		__i32 getPassward() const;
	#endif
		
		AccountAll();
		~AccountAll();
		
	private:
		__i32 mMoneyTime;
		__i32 mMoneyCount;
		__i32 mRenminbi;
	#ifdef __CLIENT__
		string mPassward;
	#endif
	#ifdef __SERVER__
		__i32 mPassward;
	#endif
	};
	typedef shared_ptr<AccountAll> AccountAllPtr;
	typedef weak_ptr<AccountAll> AccountAllWtr;
	
}
