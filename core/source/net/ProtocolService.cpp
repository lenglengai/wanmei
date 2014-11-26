#include "../../include/Include.h"

namespace std {

	bool ProtocolService::runReadBlock(ReadBlockPtr& nReadBlock, PlayerPtr& nPlayer)
	{
		__i16 version_ = 0; nReadBlock->runInt16(version_);
		SettingService& settingService_ = Singleton<SettingService>::instance();
		if (ERRORINT::MUSTUPDATE == settingService_.checkVersion(version_)) {
			return false;
		}
		__i32 protocolId = 0; nReadBlock->runInt32(protocolId);
		map<__i32, IProtocol *>::iterator it = mProtocols.find(protocolId);
		if (it == mProtocols.end()) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(protocolId));
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
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(protocolId));
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
