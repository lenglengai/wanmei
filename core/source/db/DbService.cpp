#include "../../include/Include.h"

namespace std {
	
	bool DbService::runPreinit()
	{
		return true;
	}
	
	void DbService::runInit()
	{
	}
	
	DbService::DbService()
	{
	}
	
	DbService::~DbService()
	{
	}
	
	static Preinit<DbService> sDbServicePreinit;
	
}
