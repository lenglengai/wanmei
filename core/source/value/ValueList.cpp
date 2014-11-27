#include "../../include/Include.h"

namespace std {

	void ValueList::insert(__i32 nNo, ValuePtr& nValue) {
		__i32 index_ = mClosedNo << 16 + nNo;
		auto it = mValues.find(index_);
		if ( it != mValues.end() ) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_2(mClosedNo, nNo));
			return;
		}
		mValues[index_] = nValue;
	}
	
	void ValueList::setClosedNo(__i32 nClosedNo)
	{
		mClosedNo = nClosedNo;
	}
	
	ValuePtr& ValueList::getAt(__i32 nId, __i32 nNo) {
		__i32 index_ = nId << 16 + nNo;
		auto it = mValues.find(index_);
		if ( it == mValues.end() ) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_2(nId, nNo));
			return __defaultptr<IValue>();
		}
		return mValues[index_];
	}
	
	void ValueList::runClear()
	{
		mClosedNo = 0;
		mValues.clear();
	}
	
	ValueList::ValueList()
	{
		this->runClear();
	}
	
	ValueList::~ValueList()
	{
		this->runClear();
	}
	
}
