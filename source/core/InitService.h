#pragma once

namespace std {

	class __funapi InitService : public IService
	{
	#ifdef __CONSOLE__
	public:
		void runCommand(const CommandArgs& nCommandArgs);
	#ifdef __CLIENT__
		void setClientConsole(const bool nClientConsole);
	#endif
	private:
		const StringWriterPtr commandInfo(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandResume(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandPause(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandFindName(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandFindId(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandInitTable(const CommandArgs& nCommandArgs);
	#endif
	
	public:
		void registerService(__i32 nClassId, IService * nService);
		
		static InitService * getInitService();
		
		bool runPreinit() OVERRIDE FINAL;
		
		void runLuaApi() OVERRIDE FINAL;
		bool runConfig() OVERRIDE FINAL;
		bool runInitDb() OVERRIDE FINAL;
		bool runInitTable() OVERRIDE FINAL;
		
		bool loadBegin() OVERRIDE FINAL;
		bool loading() OVERRIDE FINAL;
		bool loadEnd() OVERRIDE FINAL;
		
		bool initBegin() OVERRIDE FINAL;
		bool initing() OVERRIDE FINAL;
		bool initEnd() OVERRIDE FINAL;
		
		void startBegin() OVERRIDE FINAL;
		void starting() OVERRIDE FINAL;
		void startEnd() OVERRIDE FINAL;
		
		void runing() OVERRIDE FINAL;
		
		void stopBegin() OVERRIDE FINAL;
		void stoping() OVERRIDE FINAL;
		void stopEnd() OVERRIDE FINAL;
		
		void runClear() OVERRIDE FINAL;
		
		void resumeBegin() OVERRIDE FINAL;
		void resuming() OVERRIDE FINAL;
		void resumeEnd() OVERRIDE FINAL;
		
		void pauseBegin() OVERRIDE FINAL;
		void pausing() OVERRIDE FINAL;
		void pauseEnd() OVERRIDE FINAL;
		
		bool isPause() const;
		
		InitService();
		~InitService();
		
	private:
		map<__i32, IService *> mServices;
		atomic<bool> mPause;
	#ifdef __CONSOLE__
		bool mClientConsole;
		HandlePtr mConsole;
	#endif
	};

}
