#include "../../common/DefInc.h"

#include "../../service/log/LogService.h"
#include "../../service/crc/CrcService.h"

#include "IProtocol.h"

namespace std {

	bool IProtocol::runReadBlock(ReadBlockPtr& nReadBlock, SessionPtr& nSession)
	{
		__i32 packetType_ = 0; nReadBlock->runInt32(packetType_);
		IPacketId * packetId_ = this->getPacketId(packetType_);
		if (nullptr == packetId_) {
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_2("getPacketId ", packetType_));
			return false;
		}
		PacketPtr packet_ = packetId_->createPacket();
		__i32 protocolId_ = this->getProtocolId();
		packet_->setHeader(protocolId_, packetType_);
		BlockPtr block_ = nReadBlock;
		packet_->runBlock(block_);
		if (packet_->isDefault()) {
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1("packet isDefault"));
			return false;
		}
		return this->runPacket(packet_, nSession);
	}

	bool IProtocol::runPacket(PacketPtr& nPacket, SessionPtr& nSession)
	{
		return nPacket->handleRun(nSession);
	}

	IPacketId * IProtocol::getPacketId(__i32 nPacketType)
	{
		map<__i32, PacketIdPtr>::iterator it = mPacketIds.find(nPacketType);
		if (it == mPacketIds.end()) {
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(nPacketType));
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
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(packetId_));
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
