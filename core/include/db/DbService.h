#pragma once

namespace std {

	class DbService : boost::noncopyable
	{
	public:
		void runSql(
		bool runPreinit();
		void runInit();
		
		DbService();
		~DbService();
		
	private:
		DataBasePtr mDataBase;
	};
	
}
