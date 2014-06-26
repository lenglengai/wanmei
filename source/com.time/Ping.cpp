
#include "../com.common/DefInc.h"

#include "Ping.h"

namespace std {

	bool PingPacket::runBlock(BlockPtr& nBlockPtr)
	{
		return true;
	}

	bool PingPacket::isDefault()
	{
		return true;
	}

	#define PACKETRUNSIZE 1
 	static PacketRun sPacketRun[PACKETRUNSIZE] = {
 		{ internalCreatePacket<PingPacket>, boost::bind(&ContextProtocol::runContextPacket, Singleton<ContextProtocol>::instance(), _1, _2) }
 	};

	bool ContextProtocol::runContextPacket(PacketPtr& nPacket, SessionPtr& nSession)
	{
		return true;
	}

	PacketRun * ContextProtocol::getPacketRun(__i16 nPacketType)
	{
 		if ( (nPacketType <= PACKETRUNSIZE) && (nPacketType > 0) ) {
 			return (&sPacketRun[nPacketType]);
 		}
		return nullptr;
	}

	const char *  ContextProtocol::getProtocolName()
	{
		return "ContextProtocol";
	}

}
