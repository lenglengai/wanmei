#pragma once

#ifdef __WITHMYSQL__
namespace std {

	class DbService : IService
	{
	public:
		__i16 runSql(ISqlHeadstream * nSqlHeadstream);
		
		bool runPreinit();
		void runLoad();
		void runInitDB();
		
		DbService();
		~DbService();
		
	private:
		DataBasePtr mDataBase;
	};
	
}
#endif
