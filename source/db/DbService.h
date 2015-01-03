#pragma once

#ifdef __WITHMYSQL__
namespace std {

	class DbService : public IService
	{
	public:
		__i16 runSql(ISqlHeadstream * nSqlHeadstream);
		__i16 runSql(const char * nSql);
		
		__i16 runLoginSql(ISqlHeadstream * nSqlHeadstream);
		__i16 runLoginSql(const char * nSql);
		
		__i16 runLogSql(ISqlHeadstream * nSqlHeadstream);
		__i16 runLogSql(const char * nSql);
		
	private:
	#ifdef __CONSOLE__
		const StringWriterPtr commandInfo(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandRunSql(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandRunLogSql(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandRunLoginSql(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandCreateDb(const CommandArgs& nCommandArgs);
	#endif
	public:
		bool runPreinit();
		void runLoad();
		
		DbService();
		~DbService();
		
	private:
		DataBasePtr mGameDb;
		DataBasePtr mLoginDb;
		DataBasePtr mLogDb;
	};
	
}
#endif
