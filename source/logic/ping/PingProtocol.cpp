#include "../LogicInc.h"

#ifdef __PING__
namespace std {

	bool PingProtocol::runPreinit()
	{
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("PingProtocol runPreinit!"));
	#endif
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&PingProtocol::runInit, this));
		initService_.m_tRunStart0.connect(boost::bind(&PingProtocol::runStart, this));
	#ifdef __LOG__
		logService_.logInfo(log_1("PingProtocol runPreinit finish!"));
	#endif
		return true;
	}

	void PingProtocol::runInit()
	{
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("PingProtocol runInit!"));
	#endif
		ProtocolService& protocolService_ =  Singleton<ProtocolService>::instance();
		protocolService_.runRegister(this);

	#ifdef __CLIENT__
		TcpClient& tcpClient_ = Singleton<TcpClient>::instance();
		PropertyIdPtr propertyIdPtr_ = PropertyIdPtr(new PropertyId<PingSecond>());
		tcpClient_.registerCreate(propertyIdPtr_);

		mPingTick.reset(new PingTick(this));

		this->addPacketId(PacketIdPtr(new PacketId<S2CPing>()));
	#endif

	#ifdef __SERVER__
		TcpServer& tcpServer_ = Singleton<TcpServer>::instance();
		PropertyIdPtr propertyIdPtr_ = PropertyIdPtr(new PropertyId<PingSecond>());
		tcpServer_.registerCreate(propertyIdPtr_);

		this->addPacketId(PacketIdPtr(new PacketId<C2SPing>()));
	#endif
	#ifdef __LOG__
		logService_.logInfo(log_1("PingProtocol runInit finish!"));
	#endif
	}

	void PingProtocol::runStart()
	{
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("PingProtocol runStart!"));
	#endif
	#ifdef __CLIENT__
		HandleService& handleService_ = Singleton<HandleService>::instance();
		ContextPtr context_ = mPingTick;
		handleService_.addContext(context_, 1);
	#endif
	#ifdef __LOG__
		logService_.logInfo(log_1("PingProtocol runStart finish!"));
	#endif
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
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_2("current ping is : ", mPing));
	#endif
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
