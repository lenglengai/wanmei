#include "../LogicInc.h"

#ifdef __ACCOUNT__
namespace std {

	bool AccountProtocol::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&AccountProtocol::runInit, this));
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	#endif
		return true;
	}

	void AccountProtocol::runInit()
	{
		ProtocolService& protocolService_ =  Singleton<ProtocolService>::instance();
		protocolService_.runRegister(this);
	#ifdef __CLIENT__
		this->addPacketId(PacketIdPtr(new PacketId<S2CLogin>()));
	#endif
	#ifdef __SERVER__
		this->addPacketId(PacketIdPtr(new PacketId<C2SLogin>()));
	#endif
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	#endif
	}

	const char * AccountProtocol::getProtocolName()
	{
		return "AccountProtocol";
	}

	AccountProtocol::AccountProtocol()

	{
	}

	AccountProtocol::~AccountProtocol()
	{

	}
	
	static Preinit<AccountProtocol> sAccountProtocolPreinit;

}
#endif
