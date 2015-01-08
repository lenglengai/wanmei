#pragma once

#include "IDataBase.h"

#ifdef __WITHSQL__
namespace std {

	class DbService : public IService
	{
	public:
		__i16 runSql(ISqlHeadstream * nSqlHeadstream);
		__i16 runSql(const char * nSql);
		
	#ifdef __WITHMYSQL__
		__i16 runLoginSql(ISqlHeadstream * nSqlHeadstream);
		__i16 runLoginSql(const char * nSql);
		
		__i16 runLogSql(ISqlHeadstream * nSqlHeadstream);
		__i16 runLogSql(const char * nSql);
	#endif
	
	private:
	#ifdef __CONSOLE__
		const StringWriterPtr commandInfo(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandRunSql(const CommandArgs& nCommandArgs);
	#ifdef __WITHMYSQL__
		const StringWriterPtr commandRunLogSql(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandRunLoginSql(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandCreateDb(const CommandArgs& nCommandArgs);
	#endif
	#endif
	public:
		bool runPreinit() OVERRIDE FINAL;
		void runConfig() OVERRIDE FINAL;
		void runInitDb() OVERRIDE FINAL;
		void stopEnd() OVERRIDE FINAL;
		
		DbService();
		~DbService();
		
	private:
		DataBasePtr mGameDb;
	#ifdef __WITHMYSQL__
		DataBasePtr mLoginDb;
		DataBasePtr mLogDb;
	#endif
	};
	
}
#endif
