#pragma once

namespace std {

	class ServiceMgr : public IService
	{
	public:
		template <class __t>
		void registerService(__t * nService)
		{
			string className_("");
			__i32 classId_ = __classinfo<__t>(className_);
			auto it = mServices.find(classId_);
			if ( it != mServices.end() ) {
				LogService& logService_ = Singleton<LogService>::instance();
				logService_.logError(log_2(className_, classId_));
				return;
			}
			mServices[classId_] = nService;
		}
		void runCommand(const CommandArgs& nCommandArgs) const;
	#if defined(__CONSOLE__) ||  defined(__CLIENT__)
		void setClientConsole(const bool nClientConsole);
	#endif
	
	private:
	#ifdef __CONSOLE__
		const StringWriterPtr commandInfo(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandFindName(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandFindId(const CommandArgs& nCommandArgs);
	#endif
	
	public:
		bool runPreinit();
		void runInit();
	#ifdef __CONSOLE__
		void runConsoleCommand(bool nCommand);
	#endif
		void runStart();
		void runStop();
		
		ServiceMgr();
		~ServiceMgr();
		
	private:
		map<__i32, IService *> mServices;
	#ifdef __CONSOLE__
		HandlePtr mConsoleHandle;
		bool mClientConsole;
		bool mCommand;
	#endif
	};
	
}
