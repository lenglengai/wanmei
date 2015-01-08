#include "../Logic.h"
#include "C2SPing.h"

#ifdef __PING__
namespace std {

#ifdef __SERVER__
	bool C2SPing::handleRun(SessionPtr& nSession)
	{
		__i32 second_ = nSession->getSecond();
		if (second_ != mSecond) return false;
		RandomService& randomService_ = Singleton<RandomService>::instance();
		second_ = randomService_.runRandom();
		nSession->setSecond(second_);
		PacketPtr packet_(new S2CPing(second_));
		nSession->runSend(packet_);
		return true;
	}
#endif
	
	bool C2SPing::runBlock(BlockPtr& nBlock)
	{
		nBlock->runInt32(mSecond);
		return true;
	}

	void C2SPing::setSecond(const __i32 nSecond)
	{
		mSecond = nSecond;
	}

	__i32 C2SPing::getSecond() const
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
