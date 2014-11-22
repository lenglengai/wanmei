#include "../LogicInc.h"

#ifdef __PING__
namespace std {

	bool PingProtocol::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&PingProtocol::runInit, this));
		initService_.m_tRunStart0.connect(boost::bind(&PingProtocol::runStart, this));

		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
		return true;
	}

	void PingProtocol::runInit()
	{
		ProtocolService& protocolService_ =  Singleton<ProtocolService>::instance();
		protocolService_.runRegister(this);

	#ifdef __CLIENT__
		TcpClient& tcpClient_ = Singleton<TcpClient>::instance();
		PropertyIdPtr propertyIdPtr_ = PropertyIdPtr(new PropertyId<PingSecond>());
		tcpClient_.registerCreate(propertyIdPtr_);

		mPingTick.reset(new PingTick());

		this->addPacketId(PacketIdPtr(new PacketId<S2CPing>()));
	#endif

	#ifdef __SERVER__
		TcpServer& tcpServer_ = Singleton<TcpServer>::instance();
		PropertyIdPtr propertyIdPtr_ = PropertyIdPtr(new PropertyId<PingSecond>());
		tcpServer_.registerCreate(propertyIdPtr_);

		this->addPacketId(PacketIdPtr(new PacketId<C2SPing>()));
	#endif
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}

	void PingProtocol::runStart()
	{
	#ifdef __CLIENT__
		HandleService& handleService_ = Singleton<HandleService>::instance();
		ContextPtr context_ = std::dynamic_pointer_cast<Context, PingTick>(mPingTick);
		handleService_.addContext(context_, 1);
	#endif
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}

#ifdef __CLIENT__
	void PingProtocol::startPing()
	{
		TimeService& timeService_ = Singleton<TimeService>::instance();
		mClock = timeService_.getNowSecond();
	}

	void PingProtocol::finishPing()
	{
		TimeService& timeService_ = Singleton<TimeService>::instance();
		__i64 second_ = timeService_.getNowSecond();
		mPing = second_ - mClock;

		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_2("current ping is : ", mPing));
	}
#endif

	const char * PingProtocol::getProtocolName()
	{
		return "PingProtocol";
	}

	PingProtocol::PingProtocol()
#ifdef __CLIENT__
		: mClock(0)
		, mPing(0)
#endif
	{
	}

	PingProtocol::~PingProtocol()
	{
#ifdef __CLIENT__
		mClock = 0;
		mPing = 0;
#endif
	}
	
	static Preinit<PingProtocol> sPingProtocolPreinit;

}
#endif
