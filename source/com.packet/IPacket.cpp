#include "../com.common/DefInc.h"

namespace std {

	bool IPacket::handleRun(SessionPtr& nSession)
	{
		return true;
	}

	bool IPacket::runBlock(BlockPtr& nBlock)
	{
		nBlock->runInt32(mProtocol);
		nBlock->runInt16(mPacket);
	}

	bool IPacket::isDefault()
	{
		return ((0 == mProtocol) || (0 == mPacket));
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
