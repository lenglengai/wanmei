#include "../Common.h"
#include "IPacket.h"

#ifdef __NET__
namespace std {

	bool IPacket::handleRun(SessionPtr& nSession)
	{
		return true;
	}

	void IPacket::setHeader(__i32 nProtocol, __i32 nPacket)
	{
		mProtocol = nProtocol;
		mPacket = nPacket;
	}

	bool IPacket::runHeader(BlockPtr& nBlock)
	{
		nBlock->runInt32(mProtocol);
		nBlock->runInt32(mPacket);
		return true;
	}

	bool IPacket::isDefault()
	{
		return ((0 == mProtocol) || (0 == mPacket));
	}

	void IPacket::runInit()
	{
	}

	IPacket::IPacket()
		: mProtocol(0)
		, mPacket(0)
	{
	}

	IPacket::~IPacket()
	{
		mProtocol = 0;
		mPacket = 0;
	}

}
#endif
