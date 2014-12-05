#include "../LogicInc.h"

namespace std {
	
#ifdef __CLIENT__
	bool S2CSwitchWire::handleRun(PlayerPtr& nPlayer)
	{
		nPlayer->setWireId(mWireId);
		return true;
	}
#endif

	bool S2CSwitchWire::runBlock(BlockPtr& nBlock)
	{
		nBlock->runInt64(mWireId);
		return true;
	}

	bool S2CSwitchWire::isDefault()
	{
		if (0 == mWireId) return true;
		return IPacket::isDefault();
	}

	void S2CSwitchWire::setWireId(__i32 nWireId)
	{
		mWireId = nWireId;
	}

	__i32 S2CSwitchWire::getWireId()
	{
		return mWireId;
	}

	S2CSwitchWire::S2CSwitchWire()
		: mWireId(0)
	{
	}

	S2CSwitchWire::S2CSwitchWire(__i32 nWireId)
		: mWireId(nWireId)
	{
	}

	S2CSwitchWire::~S2CSwitchWire()
	{
		mWireId = 0;
	}
	
}
