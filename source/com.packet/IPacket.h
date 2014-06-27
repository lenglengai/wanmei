#pragma once

#include "../com.block/IBlock.h"

namespace std {

	class IPacket
	{
	public:
		virtual bool runBlock(BlockPtr& nBlock);
		virtual bool isDefault();
	private:
		__i32 mProtocol;
		__i16 mPacket;
	};
	typedef boost::shared_ptr<IPacket> PacketPtr;

	template<class T>
	PacketPtr internalCreatePacket()
	{
		return PacketPtr(new T());
	}

}
