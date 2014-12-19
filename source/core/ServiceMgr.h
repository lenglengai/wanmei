#pragma once

namespace std {

	class ServiceMgr : public IService
	{
	public:
		template <class __t>
		void registerService(__t * nService)
		{
			string className_("");
			__i32 classId_ = __classid<__t>(className_);
			auto it = mServices.find(classId_);
			if ( it != mServices.end() ) {
				LogService& logService_ = Singleton<LogService>::instance();
				logService_.logError(log_2(className_. classId_));
				return;
			}
			mServices[classId_] = nService;
		}
	#ifdef __CONSOLE__
		void runCommand(const CommandArgs& nCommand);
		void setClientConsole(bool nClientConsole);
	#endif
	
	private:
	#ifdef __CONSOLE__
		StringWriterPtr runClassId(const CommandArgs& nCommand);
	#endif
	
	public:
		bool runPreinit();
		void runInit();
		void runStart();
		void runStop();
		
		ServiceMgr();
		~ServiceMgr();
		
	private:
		std::map<__i32, IService *> mServices;
	#ifdef __CONSOLE__
		HandlePtr mConsoleHandle;
		bool mClientConsole;
	#endif
	};
	
}
