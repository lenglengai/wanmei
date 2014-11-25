#include "../LogicInc.h"

#ifdef __PING__
namespace std {

	const char * C2SPing::sPacketName = "C2SPing";

#ifdef __SERVER__
	bool C2SPing::handleRun(PlayerPtr& nPlayer)
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
	
	bool C2SPing::runBlock(BlockPtr& nBlock)
	{
		nBlock->runInt32(mSecond);
		return true;
	}

	void C2SPing::setSecond(__i32 nSecond)
	{
		mSecond = nSecond;
	}

	__i32 C2SPing::getSecond()
	{
		return mSecond;
	}

	C2SPing::C2SPing()
		: mSecond(0)
	{
	}

	C2SPing::C2SPing(__i32 nSecond)
		: mSecond(nSecond)
	{
	}

	C2SPing::~C2SPing()
	{
		mSecond = 0;
	}
	
}
#endif
