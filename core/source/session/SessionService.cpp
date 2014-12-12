#include "../../include/Include.h"

namespace std{

	void SessionService::removeSession(SessionPtr& nSession)
	{
		__i32 sessionId_ = nSession->getSessionId();
		std::lock_guard<std::mutex> lock_(mMutex);
		auto it = mSessions.find(sessionId_);
		if (it != mSessions.end()) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(sessionId_));
			return;
		}
		mSessions.erase(it);
	}
	
	SessionPtr& SessionService::createSession()
	{
		IoService& ioService_ = Singleton<IoService>::instance();
		asio::io_service& ioservice = ioService_.getIoService();
		SessionPtr session_(new Session(++mSessionId, ioservice));
		std::lock_guard<std::mutex> lock_(mMutex);
		mSessions[mSessionId] = session_;
		return mSessions[mSessionId];
	}
	
	void SessionService::runClear()
	{
		mSessions.clear();
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
