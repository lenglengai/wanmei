#pragma once

#include "Player.h"

#ifdef __NET__
namespace std {

	class IProtocol
	{
	public:
		bool runReadBlock(ReadBlockPtr& nReadBlock, PlayerPtr& nPlayer);
		virtual bool runPacket(PacketPtr& nPacket, PlayerPtr& nPlayer);
		virtual const char * getProtocolName() = 0;
		IPacketId * getPacketId(__i32 nPacketType);
		void addPacketId(PacketIdPtr nPacketId);
		__i32 getProtocolId();
		
		IProtocol();
		virtual ~IProtocol();
		
	private:
		map<__i32, PacketIdPtr> mPacketIds;
		__i32 mProtocolId;
	};

}
#endif
