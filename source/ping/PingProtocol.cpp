#include "../Logic.h"

#ifdef __PING__
namespace std {

#ifdef __CONSOLE__
	const StringWriterPtr PingProtocol::commandInfo(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		string className_(""); 
		__i32 classid_ = __classinfo<PingProtocol>(className_);
		stringWriter_->runString(className_, "className");
		stringWriter_->runInt32(classid_, "classId");
		stringWriter_->runInt32(mPing, "ping");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
#endif
	
	bool PingProtocol::runPreinit()
	{
	#ifdef __CONSOLE__
		this->registerCommand("info", std::bind(&PingProtocol::commandInfo, this, placeholders::_1));
	#endif
		return true;
	}
	
	void PingProtocol::initBegin()
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

	void PingProtocol::startBegin()
	{
	#ifdef __CLIENT__
		HandleService& handleService_ = Singleton<HandleService>::instance();
		handleService_.addContext(mPingTick, 1);
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
