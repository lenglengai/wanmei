#pragma once

namespace std {

	class SessionService : public IService
	{
	public:
		void removeSession(SessionPtr& nSession);
		SessionPtr& createSession();
		void runClear();
	private:
	#ifdef __CONSOLE__
		StringWriterPtr commandInfo(const CommandArgs& nCommand);
	#endif
	
	public:
		bool runPreinit();
		
		SessionService();
		~SessionService();
		
	private:
	#ifdef __SERVER__
		map<__i32, SessionPtr> mSessions;
		std::mutex mMutex;
	#endif
	#ifdef __CLIENT__
		SessionPtr mSession;
	#endif
		__i32 mSessionId;
	};

}
