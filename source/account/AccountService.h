#pragma once

#include "AccountAll.h"

namespace std {
	
	class AccountService : public IService, public ISqlHeadstream
	{
	public:
	    void runSelect(SqlCommand * nSqlCommand) OVERRIDE FINAL;
        void runWhere(SqlCommand * nSqlCommand) OVERRIDE FINAL;
        const char * getTableName() const OVERRIDE FINAL;
        SqlType_ getSqlType() const OVERRIDE FINAL;
		
	private:
	#ifdef __CONSOLE__
		const StringWriterPtr commandInfo(const CommandArgs& nCommandArgs);
	#endif
	
	public:
		bool runPreinit() OVERRIDE FINAL;
		void runInitTable() OVERRIDE FINAL;
		void loadBegin() OVERRIDE FINAL;
		void runClear() OVERRIDE FINAL;
		
		AccountService();
		~AccountService();
		
	private:
	#ifdef __SERVER__
		map<__i64, AccountAllPtr> mAccounts;
	#endif
	#ifdef __CLIENT__
		map<__i64, AccountPtr> mAccounts;
		AccountAllPtr mAccount;
	#endif
	};

}
