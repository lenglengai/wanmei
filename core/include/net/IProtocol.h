#pragma once

namespace std {

	class IProtocol : boost::noncopyable
	{
	public:
		IPacketId * getPacketId(__i32 nPacketType);
		void addPacketId(PacketIdPtr nPacketId);
		
		IProtocol();
		virtual ~IProtocol();
		
	private:
		map<__i32, PacketIdPtr> mPacketIds;
	};

}
