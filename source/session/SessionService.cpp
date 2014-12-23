#include "../Include.h"

namespace std{

#ifdef __CONSOLE__
	StringWriterPtr SessionService::commandInfo(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		string className_(""); __i32 sessionCount_ = 0;
		__i32 classid_ = __classid<SessionService>(className_);
		stringWriter_.runString(className_className_, "className");
		stringWriter_.runInt32(classid_, "classId");
		stringWriter_.runInt32(mSessionId, "sessionId");
		{
			std::lock_guard<std::mutex> lock_(mMutex);
			sessionCount_ = mSessions.size();
		}
		stringWriter_.runInt32(sessionCount_, "sessionCount");
		return stringWriter_;
	}
#endif
	
	bool SessionService::runPreinit()
	{
	#ifdef __CONSOLE__
		this->registerCommand("info", std::bind(&SessionService::commandInfo, this, _1));
	#endif
		return true;
	}
	
	void SessionService::removeSession(SessionPtr& nSession)
	{
	#ifdef __SERVER__
		__i32 sessionId_ = nSession->getSessionId();
		std::lock_guard<std::mutex> lock_(mMutex);
		auto it = mSessions.find(sessionId_);
		if (it != mSessions.end()) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(sessionId_));
			return;
		}
		mSessions.erase(it);
	#endif
	}
	
	SessionPtr& SessionService::createSession()
	{
	#ifdef __SERVER__
		IoService& ioService_ = Singleton<IoService>::instance();
		asio::io_service& ioservice = ioService_.getIoService();
		SessionPtr session_(new Session(++mSessionId, ioservice));
		std::lock_guard<std::mutex> lock_(mMutex);
		mSessions[mSessionId] = session_;
		return mSessions[mSessionId];
	#endif
	#ifdef __CLIENT__
		mSession.reset(new Session(++mSessionId, ioservice));
		return mSession;
	#endif
	}
	
	void SessionService::runClear()
	{
	#ifdef __SERVER__
		mSessions.clear();
	#endif
		mSessionId = 0;
	}
	
	SessionService::SessionService()
	{
		this->runClear();
	}
	
	SessionService::~SessionService()
	{
		this->runClear();
	}
	
	static Preinit<SessionService> sSessionServicePreInit;
}
