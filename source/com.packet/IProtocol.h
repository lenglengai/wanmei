#pragma once

#include <boost/function.hpp>

#include "Session.h"

namespace std {

	struct PacketRun
	{
		boost::function<PacketPtr()> mPacketCreator;
		boost::function<bool (PacketPtr&, SessionPtr&)> mPacketHandle;
	};

	class IProtocol
	{
	public:
		virtual PacketRun * getPacketRun(__i16 nPacketType) = 0;
		virtual const char * getProtocolName() = 0;
		bool runReadBlock(ReadBlockPtr& nReadBlock, SessionPtr& nSession);
	};

}
