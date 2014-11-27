#include "../../include/Include.h"

namespace std {

	void Values::insert(__i32 nId, ValuePtr& nValue)
	{
		auto it = mValues.find(nId);
		if ( it != mValues.end() ) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(nId));
			return;
		}
		mValues[nId] = nValue;
	}
	
	ValuePtr& Values::getAt(__i32 nId)
	{
		auto it = mValues.find(nId);
		if ( it == mValues.end() ) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(nId));
			return __defaultptr<IValue>();
		}
		return mValues[nId];
	}
	
	void Values::runClear()
	{
		mValues.clear();
	}
	
	Values::Values()
	{
		this->runClear();
	}
	
	Values::~Values()
	{
		this->runClear();
	}
	
}
