#pragma once

#include "../com.block/Block.h"

namespace std {

	class IPacket
	{
	public:
		virtual bool runBlock(BlockPtr& nBlock) = 0;
		virtual bool isDefault() = 0;
	};
	typedef boost::shared_ptr<IPacket> PacketPtr;

	template<class T>
	PacketPtr internalCreatePacket()
	{
		return PacketPtr(new T());
	}

}
