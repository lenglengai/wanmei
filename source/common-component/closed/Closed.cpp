#include "../Common.h"

namespace std {
	
	__i32 Closed::getClosedType()
	{
	}
	
	Closed::Closed()
	{
		mClosedType = 0;
		mClosedId = 0;
	}
	
	Closed::~Closed()
		: mClosedType(0)
		, mClosedId(0)
	{
	}
	
}
