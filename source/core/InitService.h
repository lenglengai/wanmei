#pragma once

namespace std {

	class __funapi InitService : public IService
	{
	#ifdef __CONSOLE__
	public:
		void runCommand(const CommandArgs& nCommandArgs) const;
	#ifdef __CLIENT__
		void setClientConsole(const bool nClientConsole);
	#endif
	private:
		const StringWriterPtr commandInfo(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandResume(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandPause(const CommandArgs& nCommandArgs);
	#endif
	
	public:
		void registerService(__i32 nClassId, IService * nService);
		
		InitService * getInitService();
		
		bool runPreinit() OVERRIDE FINAL;
		
		void runLuaApi() OVERRIDE FINAL;
		void runConfig() OVERRIDE FINAL;
		void runInitDb() OVERRIDE FINAL;
		
		void loadBegin() OVERRIDE FINAL;
		void loading() OVERRIDE FINAL;
		void loadEnd() OVERRIDE FINAL;
		
		void initBegin() OVERRIDE FINAL;
		void initing() OVERRIDE FINAL;
		void initEnd() OVERRIDE FINAL;
		
		void startBegin() OVERRIDE FINAL;
		void starting() OVERRIDE FINAL;
		void startEnd() OVERRIDE FINAL;
		
		void runing() OVERRIDE FINAL;
		
		void stopBegin() OVERRIDE FINAL;
		void stoping() OVERRIDE FINAL;
		void stopEnd() OVERRIDE FINAL;
		
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
	#endif
	};

}
