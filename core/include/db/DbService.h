#pragma once

namespace std {

	class DbService : boost::noncopyable
	{
	public:
		void runSql(ISqlHeadstream * nSqlHeadstream);
		
		bool runPreinit();
		void runInit();
		
		DbService();
		~DbService();
		
	private:
		DataBasePtr mDataBase;
	};
	
}
