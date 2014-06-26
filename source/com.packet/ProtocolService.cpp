#include "../com.common/DefInc.h"
#include "../com.log/LogService.h"
#include "../com.crc/CrcService.h"
#include "ProtocolService.h"

namespace std {

	bool ProtocolService::runReadBlock(ReadBlockPtr& nReadBlock, SessionPtr nSession)
	{
		__i32 protocolId = 0; nReadBlock->runInt32(protocolId);
		map<__i32, IProtocol *>::iterator it = mProtocols.find(protocolId);
		if (it == mProtocols.end()) {
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(protocolId));
			return false;
		}
		IProtocol * protocol_ = it->second;
		return protocol_->runReadBlock(nReadBlock, nSession);
	}

	void ProtocolService::runRegister(IProtocol * nProtocol)
	{
		const char * protocolName = nProtocol->getProtocolName();
		CrcService& crcService_ = Singleton<CrcService>::instance();
		__i32 protocolId = crcService_.runCommon(protocolName);
		map<__i32, IProtocol *>::iterator it = mProtocols.find(protocolId);
		if (it != mProtocols.end()) {
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_2(protocolName, protocolId));
			return;
		}
		mProtocols[protocolId] = nProtocol;
	}

	ProtocolService::ProtocolService()
	{
		mProtocols.clear();
	}

	ProtocolService::~ProtocolService()
	{
		mProtocols.clear();
	}

}
