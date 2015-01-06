#pragma once

namespace std {
	
	class Account : noncopyable
	{
	public:
	#ifdef __CONSOLE__
		void runStringWriter(StringWriterPtr& nStringWriter) const;
	#endif
		void setAllRenminbi(const __i32 nAllRenminbi);
		__i32 getAllRenminbi() const;
		void setAccountName(const char * nAccountName);
		const string& getAccountName() const;
		void setAccountId(const __i64 nAccountId);
		__i64 getAccountId() const;
		
		Account();
		virtual ~Account();
		
	private:
		__i32 mAllRenminbi;
		string mAccountName;
		__i64 mAccountId;
	};
	typedef shared_ptr<Account> AccountPtr;
	typedef weak_ptr<Account> AccountWtr;
	
}
