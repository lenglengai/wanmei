#pragma once

namespace std {
	
	class Account : public ISqlStream
	{
	public:
		virtual void runSelect(SqlCommand * nSqlCommand);
		
	#ifdef __CONSOLE__
		void runStringWriter(StringWriterPtr& nStringWriter) const;
	#endif
		void setAllRenminbi(const __i32 nAllRenminbi);
		__i32 getAllRenminbi() const;
		void setAccountName(const char * nAccountName);
		const string& getAccountName() const;
		void setAccountId(const __i64 nAccountId);
		__i64 getAccountId() const;
		__i64 getKey() const;
		
		Account();
		virtual ~Account();
		
	private:
		__i64 mAccountId;
		string mAccountName;
		__i32 mAllRenminbi;
	};
	typedef shared_ptr<Account> AccountPtr;
	typedef weak_ptr<Account> AccountWtr;
	
}
