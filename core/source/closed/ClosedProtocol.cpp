#include "../../include/Include.h"

namespace std {

	bool ClosedProtocol::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&ClosedProtocol::runInit, this));

		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
		return true;
	}

	void ClosedProtocol::runInit()
	{
		ProtocolService& protocolService_ =  Singleton<ProtocolService>::instance();
		protocolService_.runRegister(this);

	#ifdef __CLIENT__
		this->addPacketId(PacketIdPtr(new PacketId<S2CClosed>()));
	#endif

	#ifdef __SERVER__
		this->addPacketId(PacketIdPtr(new PacketId<C2SClosed>()));
	#endif
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}

	ClosedProtocol::ClosedProtocol()
	{
	}

	ClosedProtocol::~ClosedProtocol()
	{
	}
	
	static Preinit<ClosedProtocol> sClosedProtocolPreinit;

}
