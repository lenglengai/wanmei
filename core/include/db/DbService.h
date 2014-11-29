#pragma once

namespace std {

	class DbService : boost::noncopyable
	{
	public:
		bool runPreinit();
		void runInit();
		
		DbService();
		~DbService();
		
	private:
		DataBasePtr mDataBase;
	};
	
}
