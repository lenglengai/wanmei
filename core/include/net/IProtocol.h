#pragma once

namespace std {

	class IProtocol : boost::noncopyable
	{
	public:
		bool runReadBlock(ReadBlockPtr& nReadBlock, PlayerPtr& nPlayer);
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
