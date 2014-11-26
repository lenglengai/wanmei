#include "../../include/Include.h"

namespace std {

	bool ClosedProtocol::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&ClosedProtocol::runInit, this));
		initService_.m_tRunStart0.connect(boost::bind(&ClosedProtocol::runStart, this));

		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
		return true;
	}

	void ClosedProtocol::runInit()
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

	void ClosedProtocol::runStart()
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
	void ClosedProtocol::startPing()
	{
		TimeService& timeService_ = Singleton<TimeService>::instance();
		mClock = timeService_.getLocalTime();
	}

	void ClosedProtocol::finishPing()
	{
		TimeService& timeService_ = Singleton<TimeService>::instance();
		__i64 second_ = timeService_.getLocalTime();
		mPing = second_ - mClock;

		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_2("current ping is", mPing));
	}
#endif

	const char * ClosedProtocol::getProtocolName()
	{
		return "PingProtocol";
	}

	ClosedProtocol::ClosedProtocol()
#ifdef __CLIENT__
		: mClock(0)
		, mPing(0)
#endif
	{
	}

	ClosedProtocol::~ClosedProtocol()
	{
#ifdef __CLIENT__
		mClock = 0;
		mPing = 0;
#endif
	}
	
	static Preinit<ClosedProtocol> sClosedProtocolPreinit;

}
