#pragma once

namespace std {

	class SessionService : public IService
	{
	public:
		void removeSession(__i32 nSessionId);
		SessionPtr& createSession();
				
	#ifdef __CLIENT__
		SessionPtr& getSession();
	#endif
		
	private:
	#ifdef __CONSOLE__
		const StringWriterPtr commandInfo(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandFindId(const CommandArgs& nCommandArgs);
	#endif
	
	public:
		bool runPreinit() OVERRIDE FINAL;
		void runClear() OVERRIDE FINAL;
		
		SessionService();
		~SessionService();
		
	private:
	#ifdef __SERVER__
		map<__i32, SessionPtr> mSessions;
		mutex mMutex;
	#endif
	#ifdef __CLIENT__
		SessionPtr mSession;
	#endif
		__i32 mSessionId;
	};

}
