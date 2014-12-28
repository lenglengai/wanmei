#include "../Include.h"

namespace std{

#ifdef __CONSOLE__
	const StringWriterPtr WorldService::commandInfo(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		string className_(""); 
		__i32 classid_ = __classinfo<WorldService>(className_);
		stringWriter_->runString(className_, "className");
		stringWriter_->runInt32(classid_, "classId");
	#ifdef __SERVER__
		stringWriter_->runKeyStream(mWorlds, "worlds");
	#endif
	#ifdef __CLIENT__
		stringWriter_->runStream(mWorld, "world");
	#endif
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
#endif
	
#ifdef __CLIENT__
	PlayerPtr& WorldService::getPlayer()
	{
		return mWorld->getPlayer();
	}
#endif
	
	const char * WorldService::streamName() const
	{
		return "worldService";
	}
	
	const char * WorldService::streamUrl() const
	{
	#ifdef __SERVER__
		return "worldServer.xml";
	#endif
	#ifdef __CLIENT__
		return "worldClient.xml";
	#endif
	}
	
	bool WorldService::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunLoad0.connect(boost::bind(&WorldService::runLoad, this));
		initService_.m_tRunInit0.connect(boost::bind(&WorldService::runInit, this));
		initService_.m_tRunStart0.connect(boost::bind(&WorldService::runStart, this));
		initService_.m_tRunExit.connect(boost::bind(&WorldService::runExit, this));
		return true;
	}
	
	void WorldService::runLoad()
	{
		ArchiveService& archiveService_ = Singleton<ArchiveService>::instance();
		archiveService_.loadStream(this);
	}
	
	void WorldService::runInit()
	{
	#ifdef __CLIENT__
		mWorld.runInit();
	#endif
	#ifdef __SERVER__
		for (auto& i : mWorlds) {
			WorldPtr& world_ = i.second;
			world_->runInit();
		}
	#endif
	}
	
	void WorldService::runStart()
	{
		HandleService& handleService_ = Singleton<HandleService>::instance();
	#ifdef __CLIENT__
		ContextPtr context_ = dynamic_pointer_cast<Context, World>(mWorld);
		handleService_.addContext(context_, mWorldConfig.getHandleId());
	#endif
	#ifdef __SERVER__
		for (auto& i : mWorlds) {
			WorldPtr& world_ = i.second;
			ContextPtr context_ = dynamic_pointer_cast<Context, World>(world_);
			handleService_.addContext(context_, world_->getId());
		}
	#endif
	}
	
	void WorldService::runExit()
	{
		this->runClear();
	}
	
	void WorldService::runClear()
	{
	#ifdef __SERVER__
		mWorlds.clear();
	#endif
	}
	
	WorldService::WorldService()
	{
		this->runClear();
	}
	
	WorldService::~WorldService()
	{
		this->runClear();
	}
	
	static Preinit0<WorldService> sWorldServicePreInit;
}
