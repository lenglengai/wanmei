#include "../Common.h"

#ifdef __NET__
namespace std {

	bool IPacket::handleRun(SessionPtr& nSession)
	{
		return true;
	}

	void IPacket::setHeader(__i32 nOffline, __i32 nOnline, __i32 nPacket)
	{
		mOffline = nOffline;
		mOnline = nOnline;
		mPacket = nPacket;
	}

	bool IPacket::runHeader(BlockPtr& nBlock)
	{
		nBlock->runInt32(mOffline);
		nBlock->runInt32(mOnline);
		nBlock->runInt32(mPacket);
		return true;
	}

	bool IPacket::isDefault()
	{
		return ((0 == mOffline) || (0 == mPacket));
	}

	void IPacket::runInit()
	{
	}

	IPacket::IPacket()
		: mOffline(0)
		, mPacket(0)
		, mOnline(0)
	{
	}

	IPacket::~IPacket()
	{
		mOffline = 0;
		mOnline = 0;
		mPacket = 0;
	}

}
#endif
