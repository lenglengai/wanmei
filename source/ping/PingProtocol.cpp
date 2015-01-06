#include "../Logic.h"

#ifdef __PING__
namespace std {

	bool PingProtocol::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&PingProtocol::runInit, this));
		initService_.m_tRunStart0.connect(boost::bind(&PingProtocol::runStart, this));
		return true;
	}

	void PingProtocol::runInit()
	{
		ProtocolService& protocolService_ =  Singleton<ProtocolService>::instance();
		protocolService_.runRegister(this);

	#ifdef __CLIENT__
		this->addPacketId(PacketIdPtr(new PacketId<S2CPing>()));
		mPingTick.reset(new PingTick());
	#endif

	#ifdef __SERVER__
		this->addPacketId(PacketIdPtr(new PacketId<C2SPing>()));
	#endif
	}

	void PingProtocol::runStart()
	{
	#ifdef __CLIENT__
		HandleService& handleService_ = Singleton<HandleService>::instance();
		ContextPtr context_ = dynamic_pointer_cast<Context, PingTick>(mPingTick);
		handleService_.addContext(context_, 1);
	#endif
	}

#ifdef __CLIENT__
	void PingProtocol::startPing()
	{
		TimeService& timeService_ = Service<TimeService>::instance();
		mClock = timeService_.getLocalTime();
	}

	void PingProtocol::finishPing()
	{
		TimeService& timeService_ = Singleton<TimeService>::instance();
		__i64 second_ = timeService_.getLocalTime();
		mPing = second_ - mClock;

		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_2("current ping is", mPing));
	}
#endif

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
	
	static Service<PingProtocol> sPingProtocol;

}
#endif
