#pragma once

#include "IDataBase.h"

#ifdef __WITHSQL__
namespace std {

	class DbService : public IService
	{
	public:
		__i16 runSql(ISqlHeadstream * nSqlHeadstream);
		__i16 runSql(const char * nSql);
		
	#ifdef __GAME__
		__i16 runLogSql(ISqlHeadstream * nSqlHeadstream);
		__i16 runLogSql(const char * nSql);
	#endif
		
	private:
	#ifdef __CONSOLE__
		const StringWriterPtr commandInfo(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandRunSql(const CommandArgs& nCommandArgs);
	#ifdef __GAME__
		const StringWriterPtr commandRunLogSql(const CommandArgs& nCommandArgs);
	#endif
	#endif
	public:
		bool runPreinit() OVERRIDE FINAL;
		bool runConfig() OVERRIDE FINAL;
		bool runInitDb() OVERRIDE FINAL;
		void stopEnd() OVERRIDE FINAL;
		
		DbService();
		~DbService();
		
	private:
		DataBasePtr mGameDb;
	#ifdef __GAME__
		DataBasePtr mLogDb;
	#endif
	};
	
}
#endif
