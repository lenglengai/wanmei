#include "../../include/Include.h"

namespace std{

	bool WireService::pushPacket(PacketPtr& nPacket, __i16 nWireId)
	{
	#ifdef __SERVER__
		nPacket->setPlayer(nPlayer);
		auto it = mSingleWires.find(nWireId);
		if ( it == mSingleWires.end())  {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(nWireId));
			return false;
		}
		SingleWirePtr& singleWire_ = it->second;
		singleWire_->pushPacket(nPacket);
	#endif
	#ifdef __CLIENT__
		mSingleWire->pushPacket(nPacket);
	#endif
		return true;
	}
	
	bool WireService::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&PlayerService::runInit, this));
		initService_.m_tRunStart0.connect(boost::bind(&PlayerService::runStart, this));

		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
		return true;
	}
	
	void WireService::runInit()
	{
	#ifdef __CLIENT__
		mSingleWire.reset(new SingleWire());
	#endif

	#if defined(__SERVER__) && defined(__WITHCPU__)
		CpuService& cpuService_ = Singleton<CpuService>::instance();
		__i16 cpuCount = cpuService_.getCpuCount();
		for ( __i16 i = 1; i <= cpuCount; ++i ) {
			SingleWirePtr singleWire_(new SingleWire());
			mSingleWires[i] = singleWire_;
		}
	#endif
	
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}
	
	void WireService::runStart()
	{
		HandleService& handleService_ = Singleton<HandleService>::instance();
		
	#ifdef __CLIENT__
		mSingleWire.reset(new SingleWire());
		ContextPtr context_ = std::dynamic_pointer_cast<Context, SingleWire>(mSingleWire);
		handleService_.addContext(context_, 1);
	#endif

	#if defined(__SERVER__) && defined(__WITHCPU__)
		__i32 contextId_ = 1;
		auto it = mSingleWires.begin();
		for ( ; it != mSingleWires.end(); ++it ) {
			SingleWirePtr& singleWire_ = it->second;
			ContextPtr context_ = std::dynamic_pointer_cast<Context, SingleWire>(singleWire_);
			handleService_.addContext(context_, contextId_);
			contextId_++;
		}
	#endif
	
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}
	
	void WireService::runClear()
	{
	#ifdef __SERVER__
		mSingleWires.clear();
	#endif
	}
	
	WireService::WireService()
	{
		this->runClear();
	}
	
	WireService::~WireService()
	{
		this->runClear();
	}
	
	static Preinit<WireService> sWireServicePreInit;
}
