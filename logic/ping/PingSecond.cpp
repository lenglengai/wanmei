#include "../LogicInc.h"

#ifdef __PING__
namespace std {

	__i32 PingSecond::sPropertyId = 0x1FFFF;
	
	void PingSecond::setSecond(__i32 nSecond)
	{
		mSecond = nSecond;
	}

	__i32 PingSecond::getSecond()
	{
		return mSecond;
	}

	PingSecond::PingSecond()
		: mSecond(0)
	{
	}

	PingSecond::~PingSecond()
	{
		mSecond = 0;
	}
	
}
#endif