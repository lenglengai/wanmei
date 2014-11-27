#include "../../include/Include.h"

namespace std {

	__i32 IndexValue::getClosed()
	{
		return mClosed;
	}
	
	__i32 IndexValue::getIndex()
	{
		return mIndex;
	}
	
	IndexValue::IndexValue()
		: mClosed (0)
		, mIndex (0)
	{
	}
	
	IndexValue::~IndexValue()
	{
		mClosed = 0;
		mIndex = 0;
	}

}
