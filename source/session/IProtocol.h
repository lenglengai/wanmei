#pragma once

namespace std {

	class IProtocol : noncopyable
	{
	public:
		PacketIdPtr& getPacketId(__i32 nPacketType);
		void addPacketId(PacketIdPtr& nPacketId);
		
		IProtocol();
		virtual ~IProtocol();
		
	private:
		map<__i32, PacketIdPtr> mPacketIds;
	};

}
