#include "../Logic.h"
#include "C2SPing.h"
#include "S2CPing.h"
#include "PingTick.h"

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
	#ifdef __CLIENT__
		stringWriter_->runInt32(mPing, "ping");
	#endif
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
	
	bool PingProtocol::initBegin()
	{
		ProtocolService& protocolService_ = Service<ProtocolService>::instance();
		protocolService_.runRegister(this);

	#ifdef __CLIENT__
		this->addPacketId(PacketIdPtr(new PacketId<S2CPing>()));
		mPingTick.reset(new PingTick());
	#endif

	#ifdef __SERVER__
		this->addPacketId(PacketIdPtr(new PacketId<C2SPing>()));
	#endif
		return true;
	}

	void PingProtocol::startBegin()
	{
	#ifdef __CLIENT__
		HandleService& handleService_ = Service<HandleService>::instance();
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
		TimeService& timeService_ = Service<TimeService>::instance();
		__i32 second_ = timeService_.getLocalTime();
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
