#include "../../include/Include.h"

namespace std{

#ifdef __CONSOLE__
	StringWriterPtr WorldService::commandInfo(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		string className_(""); 
		__i32 classid_ = __classid<WorldService>(className_);
		stringWriter_.runString(className_, "className");
		stringWriter_.runInt32(classid_, "classId");
	#ifdef __SERVER__
		std::map<__i16, WorldPtr> mWorlds;
	#endif
	#ifdef __CLIENT__
		WorldPtr mWorld;
	#endif
		return stringWriter_;
	}
#endif
	
	bool WorldService::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&WorldService::runInit, this));
		initService_.m_tRunStart0.connect(boost::bind(&WorldService::runStart, this));
		initService_.m_tRunExit.connect(boost::bind(&WorldService::runExit, this));
		return true;
	}
	
	void WorldService::runInit()
	{
	#ifdef __CLIENT__
		mWorld.reset(new World());
		mWorld.runInit();
	#endif
	#ifdef __SERVER__
	#endif
	}
	
	void WorldService::runStart()
	{
		HandleService& handleService_ = Singleton<HandleService>::instance();
	#ifdef __CLIENT__
		ContextPtr context_ = std::dynamic_pointer_cast<Context, World>(mWorld);
		handleService_.addContext(context_, 1);
	#endif
	#ifdef __SERVER__
		__i32 contextId_ = 1;
		for (auto& i : mWorlds) {
			WorldPtr& world_ = i.second;
			ContextPtr context_ = std::dynamic_pointer_cast<Context, World>(world_);
			handleService_.addContext(context_, contextId_);
			contextId_++;
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
