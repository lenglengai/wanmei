#include "../../include/Include.h"

namespace std {
	
	__i16 DbService::runSql(ISqlHeadstream * nSqlHeadstream)
	{
		return mDataBase->runSql(nSqlHeadstream);
	}
	
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
