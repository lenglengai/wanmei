#pragma once

#include "../com.block/ReadBlock.h"

namespace std {

	class IPacket
	{
	public:
		virtual bool runBlock(BlockPtr& nBlock) = 0;
		virtual bool isDefault() = 0;
	};
	typedef boost::shared_ptr<IPacket> PacketPtr;

}
