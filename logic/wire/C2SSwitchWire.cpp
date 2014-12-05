#include "../LogicInc.h"

namespace std {

#ifdef __SERVER__
	bool C2SSwitchWire::handleRun(PlayerPtr& nPlayer)
	{
		PropertyId<PingSecond> pingSecondId;
		PropertyPtr& property_ = nPlayer->getProperty(pingSecondId);
		PingSecondPtr pingSecondPtr_ = std::dynamic_pointer_cast<PingSecond, Property>(property_);
		__i32 second_ = pingSecondPtr_->getSecond();
		if (second_ != mSecond) return false;
		RandomService& randomService_ = Singleton<RandomService>::instance();
		second_ = randomService_.runRandom();
		pingSecondPtr_->setSecond(second_);
		TimeService& timeService_ = Singleton<TimeService>::instance();
		__i64 serverTime_ = timeService_.getServerTime();
		PacketPtr packet_(new S2CPing(second_, serverTime_));
		nPlayer->runSend(packet_);
		return true;
	}
#endif
	
	bool C2SSwitchWire::runBlock(BlockPtr& nBlock)
	{
		nBlock->runInt32(mSecond);
		return true;
	}

	void C2SSwitchWire::setSecond(__i32 nSecond)
	{
		mSecond = nSecond;
	}

	__i32 C2SSwitchWire::getSecond()
	{
		return mWire;
	}

	C2SSwitchWire::C2SSwitchWire()
		: mWire(0)
	{
	}

	C2SSwitchWire::C2SSwitchWire(__i32 nWire)
		: mWire(nWire)
	{
	}

	C2SSwitchWire::~C2SSwitchWire()
	{
		mWire = 0;
	}
	
}
