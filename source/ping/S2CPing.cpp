#include "../Logic.h"

#ifdef __PING__
namespace std {
	
#ifdef __CLIENT__
	bool S2CPing::handleRun(SessionPtr& nSession)
	{
		PingProtocol& pingProtocol_ = Singleton<PingProtocol>::instance();
		pingProtocol_.finishPing();
		nSession->setSecond(mSecond);
		return true;
	}
#endif

	bool S2CPing::runBlock(BlockPtr& nBlock)
	{
		nBlock->runInt32(mSecond);
		return true;
	}

	void S2CPing::setSecond(const __i32 nSecond)
	{
		mSecond = nSecond;
	}

	__i32 S2CPing::getSecond() const
	{
		return mSecond;
	}

	S2CPing::S2CPing()
		: mSecond(0)
	{
	}
	
	S2CPing::S2CPing(const __i32 nSecond)
		: mSecond (nSecond)
	{
	}

	S2CPing::~S2CPing()
	{
		mSecond = 0;
	}
	
}
#endif
