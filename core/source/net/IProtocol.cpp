#include "../../include/Include.h"

namespace std {

	PacketIdPtr& IProtocol::getPacketId(__i32 nPacketType)
	{
		map<__i32, PacketIdPtr>::iterator it = mPacketIds.find(nPacketType);
		if (it == mPacketIds.end()) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(nPacketType));
			return __defaultptr<IPacketId>();
		}
		return packetId_ = mPacketIds[nPacketType];
	}

	void IProtocol::addPacketId(PacketIdPtr& nPacketId)
	{
		__i32 packetId_ = nPacketId->getPacketId();
		map<__i32, PacketIdPtr>::iterator it = mPacketIds.find(packetId_);
		if (it != mPacketIds.end()) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(packetId_));
			return;
		}
		mPacketIds[packetId_] = nPacketId;
	}

	IProtocol::IProtocol()
	{
		mPacketIds.clear();
	}

	IProtocol::~IProtocol()
	{
		mPacketIds.clear();
	}

}
