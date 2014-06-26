#pragma once

#include "IPacket.h"

namespace std {

	class PingPacket : public IPacket, boost::noncopyable
	{
	public:
		bool runBlock(BlockPtr& nBlock);
		bool isDefault();
		PingPacket();
		~PingPacket();

	private:
		__i64 mSecond;
	};

	class PingProtocol : public IProtocol
	{
	public:
		PacketRun * getPacketRun(__i16 nPacketType);
		const char * getProtocolName();
	};

}
