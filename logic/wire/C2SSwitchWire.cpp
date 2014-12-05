#include "../LogicInc.h"

namespace std {

#ifdef __SERVER__
	bool C2SSwitchWire::handleRun(PlayerPtr& nPlayer)
	{
		PlayerService& playerService_ = Singleton<PlayerService>::instance();
		if ( playerService_.switchWire(nPlayer, mWireId) ) {
			PacketPtr packet_(new S2CSwitchWire(mWireId));
			nPlayer->runSend(packet_);
		}
		return true;
	}
#endif
	
	bool C2SSwitchWire::runBlock(BlockPtr& nBlock)
	{
		nBlock->runInt32(mWireId);
		return true;
	}

	void C2SSwitchWire::setWireId(__i16 nWireId)
	{
		mWireId = nWireId;
	}

	__i16 C2SSwitchWire::getWireId()
	{
		return mWireId;
	}

	C2SSwitchWire::C2SSwitchWire()
		: mWireId(0)
	{
	}

	C2SSwitchWire::C2SSwitchWire(__i16 nWireId)
		: mWireId(nWireId)
	{
	}

	C2SSwitchWire::~C2SSwitchWire()
	{
		mWireId = 0;
	}
	
}
