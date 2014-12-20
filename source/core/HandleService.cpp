#include "../Include.h"

namespace std {

#ifdef __CONSOLE__
	StringWriterPtr HandleService::commandInfo(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		string className_(""); 
		__i32 classid_ = __classid<HandleService>(className_);
		stringWriter_.runString(className_, "className");
		stringWriter_.runInt32(classid_, "classId");
		stringWriter_.runInt32(mHandleCount, "handleCount");
		return stringWriter_;
	}
#endif
	
	void HandleService::addContext(ContextPtr& nContext, __i32 nIndex)
	{
		__i32 index_ = nIndex % mHandleCount;
		HandlePtr& handle = mHandles[index_];
		handle->addContext(nContext);
	}

	bool HandleService::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&HandleService::runInit, this));
		initService_.m_tRunStart1.connect(boost::bind(&HandleService::runStart, this));
		initService_.m_tRunStop.connect(boost::bind(&HandleService::runStop, this));
		ServiceMgr& serviceMgr_ = Singleton<ServiceMgr>::instance();
		serviceMgr_.registerService(this);
		return true;
	}

	void HandleService::runInit()
	{
		for (__i32 i = 0; i < mHandleCount; ++i) {
			HandlePtr handle(new Handle());
			mHandles[i] = handle;
		}
	}

	void HandleService::runStart()
	{
		std::map<__i32, HandlePtr>::iterator it = mHandles.begin();
		for ( ; it != mHandles.end(); ++it ) {
			HandlePtr& handle = it->second;
			handle->runStart();
		}
	}

	void HandleService::runStop()
	{
		std::map<__i32, HandlePtr>::iterator it = mHandles.begin();
		for (; it != mHandles.end(); ++it) {
			HandlePtr& handle = it->second;
			handle->runStop();
		}
	}

	HandleService::HandleService()
		: mHandleCount(1)
	{
		mHandles.clear();
	}

	HandleService::~HandleService()
	{
		mHandles.clear();
		mHandleCount = 1;
	}
	
	static Preinit1<HandleService> sHandleServicePreinit;

}
