#pragma once

namespace std {

	class ServiceMgr : noncopyable
	{
	public:
		template <class T>
		void registerService(T * nService)
		{
			CrcService& crcService_ = Singleton<CrcService>::instance();
			__i32 classId_ = crcService_.runClassId<T>();
			auto it = mServices.find(classId_);
			if ( it != mServices.end() ) {
				LogService& logService_ = Singleton<LogService>::instance();
				logService_.logError(log_1(classId_));
				return;
			}
			mServices[classId_] = nService;
		}
	#ifdef __CONSOLE__
		void runCommand(std::list<std::string>& nCommand);
		void setClientConsole(bool nClientConsole);
	#endif
	
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
