#pragma once

#ifdef __WITHMYSQL__
namespace std {

	class DbService : boost::noncopyable
	{
	public:
		__i16 runSql(ISqlHeadstream * nSqlHeadstream);
		
		bool runPreinit();
		void runLoad();
		void runStart();
		
		DbService();
		~DbService();
		
	private:
		DataBasePtr mDataBase;
	};
	
}
#endif
