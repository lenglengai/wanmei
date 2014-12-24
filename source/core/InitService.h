#pragma once

namespace std {

	class __funapi InitService : public IService
	{
	public:
		static InitService * getInitService();
	private:
	#ifdef __CONSOLE__
		const StringWriterPtr commandInfo(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandResume(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandPause(const CommandArgs& nCommandArgs);
	#endif
	public:
		bool runPreinit();
		
		signals2::signal<void()> m_tRunLuaApi;
		void runLuaApi();
		
		signals2::signal<void()> m_tRunLoad0;
		void runLoad0();
		signals2::signal<void()> m_tRunLoad1;
		void runLoad1();
		
		signals2::signal<void()> m_tRunInit0;
		void runInit0();
		signals2::signal<void()> m_tRunInit1;
		void runInit1();
		
		signals2::signal<void()> m_tRunStart0;
		void runStart0();
		signals2::signal<void()> m_tRunStart1;
		void runStart1();
		
		signals2::signal<void()> m_tRunRun;
		void runRun();
		
		signals2::signal<void()> m_tRunStop;
		void runStop();
		signals2::signal<void()> m_tRunSave;
		void runSave();
		signals2::signal<void()> m_tRunExit;
		void runExit();
		
		signals2::signal<void()> m_tRunResume;
		void runResume();
		signals2::signal<void()> m_tRunPause;
		void runPause();
		
		signals2::signal<void()> m_tInitDataBase;
		void runInitDataBase();
		signals2::signal<void()> m_tInitDbTable;
		void runInitDbTable();
		
	private:
		void runClear();
		
	public:
		InitService();
		~InitService();
	};

}
