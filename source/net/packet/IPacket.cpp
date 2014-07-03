#include "../../common/DefInc.h"

#include "IPacket.h"

namespace std {

	bool IPacket::handleRun(SessionPtr& nSession)
	{
		return true;
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
