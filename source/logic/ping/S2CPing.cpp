#include "../LogicInc.h"

#ifdef __PING__
namespace std {

	const char * S2CPing::sPacketName = "S2CPing";
	
#ifdef __CLIENT__
	bool S2CPing::handleRun(PlayerPtr& nPlayer)
	{
		PingProtocol& pingProtocol_ = Singleton<PingProtocol>::instance();
		pingProtocol_.endPing();
		PropertyId<PingSecond> pingSecondId;
		PropertyPtr& property_ = nPlayer->getProperty(pingSecondId);
		PingSecondPtr pingSecondPtr_ = std::dynamic_pointer_cast<PingSecond, Property>(property_);
		pingSecondPtr_->setSecond(mSecond);
		return true;
	}
#endif

	const char * S2CPing::getPacketName()
	{
		return "C2SPing";
	}

	bool S2CPing::runBlock(BlockPtr& nBlock)
	{
		nBlock->runInt32(mSecond);
		return true;
	}

	bool S2CPing::isDefault()
	{
		if (0 == mSecond) return true;
		return IPacket::isDefault();
	}

	void S2CPing::setSecond(__i32 nSecond)
	{
		mSecond = nSecond;
	}

	__i32 S2CPing::getSecond()
	{
		return mSecond;
	}

	S2CPing::S2CPing()
		: mSecond(0)
	{
	}

	S2CPing::S2CPing(__i32 nSecond)
		: mSecond(nSecond)
	{
	}

	S2CPing::~S2CPing()
	{
		mSecond = 0;
	}
	
}
#endif
