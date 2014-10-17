#include "../Common.h"

#ifdef __NET__
namespace std {

	bool ProtocolService::runReadBlock(ReadBlockPtr& nReadBlock, PlayerPtr& nPlayer)
	{
		__i32 protocolId = 0; nReadBlock->runInt32(protocolId);
		map<__i32, IProtocol *>::iterator it = mProtocols.find(protocolId);
		if (it == mProtocols.end()) {
		#ifdef __LOG__
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(protocolId));
		#endif
			return false;
		}
		IProtocol * protocol_ = it->second;
		return protocol_->runReadBlock(nReadBlock, nPlayer);
	}

	void ProtocolService::runRegister(IProtocol * nProtocol)
	{
		__i32 protocolId = nProtocol->getProtocolId();
		map<__i32, IProtocol *>::iterator it = mProtocols.find(protocolId);
		if (it != mProtocols.end()) {
		#ifdef __LOG__
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(protocolId));
		#endif
			return;
		}
		mProtocols[protocolId] = nProtocol;
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
#endif
