#include "../Common.h"

#ifdef __NET__
namespace std {

	bool IProtocol::runReadBlock(ReadBlockPtr& nReadBlock, PlayerPtr& nPlayer)
	{
		bool inline_ = false; nReadBlock->runBool(inline_);
		__i32 packetType_ = 0; nReadBlock->runInt32(packetType_);
		IPacketId * packetId_ = this->getPacketId(packetType_);
		if (nullptr == packetId_) {
		#ifdef __LOG__
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_2("getPacketId ", packetType_));
		#endif
			return false;
		}
		PacketPtr packet_ = packetId_->createPacket();
		__i32 protocolId_ = this->getProtocolId();
		packet_->setHeader(protocolId_, inline_, packetType_);
		BlockPtr block_ = nReadBlock;
		packet_->runBlock(block_);
		if (packet_->isDefault()) {
		#ifdef __LOG__
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1("packet isDefault"));
		#endif
			return false;
		}
		if (inline_) {
			PlayerService& playerService_ = Singleton<PlayerService>::instance();
			return playerService_->pushPacket(nPacket, nPlayer);
		} else {
			return nPacket->handleRun(nPlayer);
		}
	}

	IPacketId * IProtocol::getPacketId(__i32 nPacketType)
	{
		map<__i32, PacketIdPtr>::iterator it = mPacketIds.find(nPacketType);
		if (it == mPacketIds.end()) {
		#ifdef __LOG__
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(nPacketType));
		#endif
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
		#ifdef __LOG__
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(packetId_));
		#endif
			return;
		}
		mPacketIds[packetId_] = nPacketId;
	}

	__i32 IProtocol::getProtocolId()
	{
		if (0 == mProtocolId)
		{
			CrcService& crcService_ = Singleton<CrcService>::instance();
			mProtocolId = crcService_.runCommon(this->getProtocolName());
		}
		return mProtocolId;
	}

	IProtocol::IProtocol()
		: mProtocolId(0)
	{
		mPacketIds.clear();
	}

	IProtocol::~IProtocol()
	{
		mPacketIds.clear();
		mProtocolId = 0;
	}

}
#endif
