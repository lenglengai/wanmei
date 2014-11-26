#include "../../include/Include.h"

namespace std {

	bool IProtocol::runReadBlock(ReadBlockPtr& nReadBlock, PlayerPtr& nPlayer)
	{
		bool inline_ = false; nReadBlock->runBool(inline_);
		__i32 packetType_ = 0; nReadBlock->runInt32(packetType_);
		IPacketId * packetId_ = this->getPacketId(packetType_);
		if (nullptr == packetId_) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(packetType_));
			return false;
		}
		PacketPtr packet_ = packetId_->createPacket();
		BlockPtr block_ = nReadBlock;
		packet_->runBlock(block_);
		if (packet_->isDefault()) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1("packet_->isDefault()"));
			return false;
		}
		if (inline_) {
			PlayerService& playerService_ = Singleton<PlayerService>::instance();
			return playerService_.pushPacket(packet_, nPlayer);
		} else {
			return packet_->handleRun(nPlayer);
		}
	}

	IPacketId * IProtocol::getPacketId(__i32 nPacketType)
	{
		map<__i32, PacketIdPtr>::iterator it = mPacketIds.find(nPacketType);
		if (it == mPacketIds.end()) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(nPacketType));
			return nullptr;
		}
		PacketIdPtr& packetId_ = mPacketIds[nPacketType];
		return packetId_.get();
	}

	void IProtocol::addPacketId(PacketIdPtr nPacketId)
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
