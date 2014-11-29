#include "../../include/Include.h"

namespace std {

	DbConnectionPtr MySqlDataBase::createConnection()
	{
		return DbConnectionPtr(new MySqlConnection(this));
	}
	
	MySqlDataBase::MySqlDataBase()
	{
	}
	
	MySqlDataBase::~MySqlDataBase()
	{
	}
	
}
