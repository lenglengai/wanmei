#include "../Include.h"

namespace std {

	bool Player::runSend(PacketPtr& nPacket)
	{
#ifdef __SERVER__
		for (auto& i : mSessions) {
			SessionPtr * session_ = i.second;
			(*session_)->runSend(nPacket);
		}
#endif
		if (nullptr != mSession) {
			return (*mSession)->runSend(nPacket);
		}
		return false;
	}
	
	void Player::loginSession(SessionPtr& nSession)
	{
		if (nullptr != mSession) {
			__i32 sessionId_ = mSession.getSessionId();
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(sessionId_));
			return;
		}
		mSession = &nSession;
	}
	
	void Player::logoutSession()
	{
		if (nullptr == mSession) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_0());
			return;
		}
		mSession = nullptr;
	}
	
	void Player::lookSession(SessionPtr& nSession)
	{
		__i32 sessionId_ = nSession.getSessionId();
		auto it = mSessions.find(sessionId_);
		if ( it != mSession.end() ) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(sessionId_));
			return;
		}
		nSession[sessionId_] = (&nSession);
	}
	
	void Player::lookoutSession(const __i32 nSessionId)
	{
		auto it = mSessions.find(nSessionId);
		if ( it == mSession.end() ) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(nSessionId));
			return;
		}
		nSession.erase(it);
	}

	Player::Player()
		: Tourist (RobotType_::mPlayer_)
		, mSession (nullptr)
	{
	}

	Player::~Player()
	{
		mSession = nullptr;
	}

}
