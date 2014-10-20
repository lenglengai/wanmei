#include "../LogicInc.h"

#ifdef __ACCOUNT__
namespace std {

	bool LoginProtocol::runPreinit()
	{
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("LoginProtocol runPreinit!"));
	#endif
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&LoginProtocol::runInit, this));
	#ifdef __LOG__
		logService_.logInfo(log_1("LoginProtocol runPreinit finish!"));
	#endif
		return true;
	}

	void LoginProtocol::runInit()
	{
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("LoginProtocol runInit!"));
	#endif
		ProtocolService& protocolService_ =  Singleton<ProtocolService>::instance();
		protocolService_.runRegister(this);
	#ifdef __CLIENT__
		this->addPacketId(PacketIdPtr(new PacketId<S2CLogin>()));
	#endif
	#ifdef __SERVER__
		this->addPacketId(PacketIdPtr(new PacketId<C2SLogin>()));
	#endif
	#ifdef __LOG__
		logService_.logInfo(log_1("LoginProtocol runInit finish!"));
	#endif
	}

#ifdef __CLIENT__
	bool LoginProtocol::runPacket(PacketPtr& nPacket, PlayerPtr& nPlayer)
	{
		return true;
	}
#endif

	const char * LoginProtocol::getProtocolName()
	{
		return "LoginProtocol";
	}

	LoginProtocol::LoginProtocol()
	#ifdef __CLIENT__
		: mPlayer ("")
		, mContextId (0)
		, mPassward (0)
	#endif
	{
	}

	LoginProtocol::~LoginProtocol()
	{
	#ifdef __CLIENT__
		mPlayer = "";
		mContextId = 0;
		mPassward = 0;
	#endif
	}
	
	static Preinit<LoginProtocol> sLoginProtocolPreinit;

}
#endif
