#pragma once

namespace std {

	class MySqlDataBase : public IDataBase
	{
	public:
		DbConnectionPtr createConnection();
		
	public:
		MySqlDataBase();
		~MySqlDataBase();
	};
	
}
