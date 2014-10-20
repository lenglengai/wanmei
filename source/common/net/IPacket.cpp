#include "../Common.h"

#ifdef __NET__
namespace std {

	bool IPacket::handleRun(PlayerPtr& nPlayer)
	{
		return true;
	}

	void IPacket::setHeader(__i32 nProtocol, bool nInline, __i32 nPacket)
	{
		mProtocol = nProtocol;
		mInline = nInline;
		mPacket = nPacket;
	}

	bool IPacket::runHeader(BlockPtr& nBlock)
	{
		nBlock->runInt32(mProtocol);
		nBlock->runBool(mInline);
		nBlock->runInt32(mPacket);
		return true;
	}

	__i32 IPacket::getProtocolId()
	{
		return mProtocol;
	}
	
	__i32 IPacket::getPacketId()
	{
		return mPacket;
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
		, mInline(true)
	{
	}

	IPacket::~IPacket()
	{
		mProtocol = 0;
		mInline = true;
		mPacket = 0;
	}

}
#endif
