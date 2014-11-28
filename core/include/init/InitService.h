#pragma once

namespace std {

	class __funapi InitService : boost::noncopyable
	{
	public:
		bool runPreinit(bool nConfigure = false);
		
		boost::signals2::signal<void()> m_tRunLoad0;
		void runLoad0();

		boost::signals2::signal<void()> m_tRunLoad1;
		void runLoad1();
		
		boost::signals2::signal<void()> m_tRunInit0;
		void runInit0();

		boost::signals2::signal<void()> m_tRunInit1;
		void runInit1();

		boost::signals2::signal<void()> m_tRunStart0;
		void runStart0();

		boost::signals2::signal<void()> m_tRunStart1;
		void runStart1();

		boost::signals2::signal<void()> m_tRunRun;
		void runRun();

		void runPause(bool nPause);

		bool isPause();

		boost::signals2::signal<void()> m_tRunStop;
		void runStop();
		
		boost::signals2::signal<void()> m_tRunSave;
		void runSave();
		
		boost::signals2::signal<void()> m_tRunExit;
		void runExit();
		
		void runConfigure();
		
	private:
		void runClear();

	public:
		InitService();
		~InitService();
		
	private:
		__i16 mInitType;
	};

}
