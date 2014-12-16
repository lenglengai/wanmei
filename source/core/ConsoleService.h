#pragma once

#ifdef __CONSOLE__
namespace std {

	class ConsoleService : boost::noncopyable
	{
	public:
		template <class T>
		void registerConsole(T * nConsole)
		{
			CrcService& crcService_ = Singleton<CrcService>::instance();
			__i32 classId_ = crcService_.runClassId<T>();
			auto it = mConsoles.find(classId_);
			if ( it != mConsoles.end() ) {
				LogService& logService_ = Singleton<LogService>::instance();
				logService_.logError(log_1(classId_));
				return;
			}
			mConsoles[classId_] = nConsole;
		}
		void runCommand(std::list<std::string>& nCommand);
		void setIsClient(bool nIsClient);
		
		bool runPreinit();
		void runInit();
		void runStart();
		void runStop();

		ConsoleService();
		~ConsoleService();
		
	private:
		std::map<__i32, IConsole *> mConsoles;
		ContextPtr mContext;
		HandlePtr mHandle;
		bool mIsClient;
	};

}
#endif
