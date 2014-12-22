#pragma once

namespace std {

	class SessionService : IService
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
		map<__i32, SessionPtr> mSessions;
		std::mutex mMutex;
		__i32 mSessionId;
	};

}
