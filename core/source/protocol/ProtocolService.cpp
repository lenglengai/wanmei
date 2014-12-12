#include "../../include/Include.h"

namespace std {

	bool ProtocolService::runReadBlock(ReadBlockPtr& nReadBlock, SessionPtr& nSession)
	{
		__i16 version_ = 0; nReadBlock->runInt16(version_);
		SettingService& settingService_ = Singleton<SettingService>::instance();
		if (ERRORINT::MUSTUPDATE == settingService_.checkVersion(version_)) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(version_));
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
		PacketIdPtr& packetId_ = protocol_->getPacketId(packetType_);
		if (!packetId_) {
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
		if (!inline_) {
			return packet_->handleRun(nSession);
		}
		PlayerPtr * player_ = nSession->getPlayer();
		if (nullptr == player_) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1("nullptr == player_"));
			return false;
		}
		PlayerService& playerService_ = Singleton<PlayerService>::instance();
		return playerService_.pushPacket(packet_, (*player_));
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
