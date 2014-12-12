#pragma once

namespace std {

	class SessionService : boost::noncopyable
	{
	public:
		void removeSession(SessionPtr& nSession);
		SessionPtr& createSession();
		void runClear();
		
		SessionService();
		~SessionService();
		
	private:
		map<__i32, SessionPtr> mSessions;
		std::mutex mMutex;
		__i32 mSessionId;
	};

}
