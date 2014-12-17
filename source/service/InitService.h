#pragma once

namespace std {

	class __funapi InitService : public IService
	{
	public:
	#ifdef __CONSOLE__
		StringWriterPtr runCommand(std::list<std::string>& nCommand);
	#endif
		bool runPreinit();
		
		signal<void()> m_tRunLuaApi;
		void runLuaApi();
		
		signal<void()> m_tRunLoad0;
		void runLoad0();
		signal<void()> m_tRunLoad1;
		void runLoad1();
		
		signal<void()> m_tRunInit0;
		void runInit0();
		signal<void()> m_tRunInit1;
		void runInit1();
		
		signal<void()> m_tRunStart0;
		void runStart0();
		signal<void()> m_tRunStart1;
		void runStart1();
		
		signal<void()> m_tRunRun;
		void runRun();
		
		signal<void()> m_tRunStop;
		void runStop();
		signal<void()> m_tRunSave;
		void runSave();
		signal<void()> m_tRunExit;
		void runExit();
		
		signal<void()> m_tRunResume;
		void runResume();
		signal<void()> m_tRunPause;
		void runPause();
		
		signal<void()> m_tInitDataBase;
		void runInitDataBase();
		signal<void()> m_tInitDbTable;
		void runInitDbTable();
		
	private:
		void runClear();
		
	public:
		InitService();
		~InitService();
	};

}
