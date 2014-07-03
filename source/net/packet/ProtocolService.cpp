#include "../../common/DefInc.h"

#include "../../service/log/LogService.h"

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
		__i32 protocolId = nProtocol->getProtocolId();
		map<__i32, IProtocol *>::iterator it = mProtocols.find(protocolId);
		if (it != mProtocols.end()) {
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(protocolId));
			return;
		}
		mProtocols[protocolId] = nProtocol;
	}

	void ProtocolService::runPreinit()
	{
		this->runClear();
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

}
