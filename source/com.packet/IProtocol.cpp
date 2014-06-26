#include "../com.common/DefInc.h"
#include "../com.log/LogService.h"
#include "IProtocol.h"

namespace std {

	bool IProtocol::runReadBlock(ReadBlockPtr& nReadBlock, SessionPtr& nSession)
	{
		__i16 packetType_ = 0; nReadBlock->runInt16(packetType_);
		const PacketRun * packetRun_ = this->getPacketRun(packetType_);
		if (nullptr == packetRun_) {
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_2("getPacketRun ", packetType_));
			return false;
		}
		PacketPtr packet_ = packetRun_->mPacketCreator();
		BlockPtr block_ = nReadBlock;
		packet_->runBlock(block_);
		if (packet_->isDefault()) {
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1("packet isDefault"));
			return false;
		}
		return (packetRun_->mPacketHandle)(packet_, nSession);
	}

}
