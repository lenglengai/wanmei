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
	
#ifdef __SERVER__
	void Player::loginSession(SessionPtr& nSession)
	{
		if (nullptr != mSession) {
			__i32 sessionId_ = (*mSession)->getSessionId();
			LogService& logService_ = Service<LogService>::instance();
			logService_.logError(log_1(sessionId_));
			return;
		}
		mSession = &nSession;
	}
	
	void Player::logoutSession()
	{
		if (nullptr == mSession) {
			LogService& logService_ = Service<LogService>::instance();
			logService_.logError(log_0());
			return;
		}
		mSession = nullptr;
	}
	
	void Player::lookSession(SessionPtr& nSession)
	{
		__i32 sessionId_ = nSession->getSessionId();
		auto it = mSessions.find(sessionId_);
		if ( it != mSessions.end() ) {
			LogService& logService_ = Service<LogService>::instance();
			logService_.logError(log_1(sessionId_));
			return;
		}
		mSessions[sessionId_] = (&nSession);
	}
	
	void Player::lookoutSession(const __i32 nSessionId)
	{
		auto it = mSessions.find(nSessionId);
		if ( it == mSessions.end() ) {
			LogService& logService_ = Service<LogService>::instance();
			logService_.logError(log_1(nSessionId));
			return;
		}
		mSessions.erase(it);
	}
#endif
	
	void Player::setWireId(const __i16 nWireId)
	{
		mWireId = nWireId;
	}
	
	__i16 Player::getWireId() const
	{
		return mWireId;
	}
	
	void Player::runSwitch()
	{
		mInSwitch = true;
	}
	
	void Player::runUnSwitch()
	{
		mInSwitch = false;
	}
	
	bool Player::inSwitch() const
	{
		return (true == mInSwitch);
	}
	
	void Player::runLock()
	{
		mInLock++;
	}
	
	void Player::runUnLock()
	{
		mInLock--;
	}
	
	bool Player::inLock() const
	{
		return (mInLock > 0);
	}
	
	Player::Player()
		: Tourist (PlayerType_::mPlayer_)
		, mSession (nullptr)
		, mInSwitch (false)
		, mInLock (0)
		, mWireId (0)
	{
	}
	
	Player::Player(const PlayerType_ nPlayerType)
		: Tourist (nPlayerType)
		, mSession (nullptr)
		, mInSwitch (false)
		, mInLock (0)
		, mWireId (0)
	{
	}

	Player::~Player()
	{
		mSession = nullptr;
		mInSwitch = false;
		mInLock = 0;
		mWireId = 0;
	}

}
