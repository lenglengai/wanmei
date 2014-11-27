#include "../../include/Include.h"

namespace std {

	bool ProtocolService::runReadBlock(ReadBlockPtr& nReadBlock, PlayerPtr& nPlayer)
	{
		__i16 version_ = 0; nReadBlock->runInt16(version_);
		SettingService& settingService_ = Singleton<SettingService>::instance();
		if (ERRORINT::MUSTUPDATE == settingService_.checkVersion(version_)) {
			return false;
		}
		__i32 protocolId_ = 0; nReadBlock->runInt32(protocolId_);
		map<__i32, IProtocol *>::iterator it = mProtocols.find(protocolId_);
		if (it == mProtocols.end()) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(protocolId_));
			return false;
		}
		IProtocol * protocol_ = it->second;
		bool inline_ = false; nReadBlock->runBool(inline_);
		__i32 packetType_ = 0; nReadBlock->runInt32(packetType_);
		IPacketId * packetId_ = protocol_->getPacketId(packetType_);
		if (nullptr == packetId_) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(packetType_));
			return false;
		}
		PacketPtr packet_ = packetId_->createPacket();
		packet_->setHeader(protocolId_, inline_, packetType_);
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
		}
		else {
			return packet_->handleRun(nPlayer);
		}

	}

	bool ProtocolService::runPreinit()
	{
		this->runClear();
		return true;
	}

	void ProtocolService::runClear()
	{
		mProtocols.clear();
	}

	ProtocolService::ProtocolService()
	{
		this->runClear();
	}

	ProtocolService::~ProtocolService()
	{
		this->runClear();
	}
	
	static Preinit<ProtocolService> sProtocolServicePreinit;

}
