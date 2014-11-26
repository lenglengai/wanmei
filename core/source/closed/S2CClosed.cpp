#include "../../include/Include.h"

namespace std {
	
#ifdef __CLIENT__
	bool S2CClosed::handleRun(PlayerPtr& nPlayer)
	{
		return true;
	}
#endif

	bool S2CClosed::runBlock(BlockPtr& nBlock)
	{
		return true;
	}

	bool S2CClosed::isDefault()
	{
		return IPacket::isDefault();
	}

	S2CClosed::S2CClosed()
	{
	}

	S2CClosed::~S2CClosed()
	{
	}
	
}
