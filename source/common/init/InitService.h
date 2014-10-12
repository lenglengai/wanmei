#pragma once

#include <atomic>

namespace std {

	class __funapi InitService : boost::noncopyable
	{
	private:
		struct InitType_
		{
			static const __i16 mNone_ = 0;
			static const __i16 mPreinit_ = 1;
			static const __i16 mLoad0_ = 2;
			static const __i16 mLoad1_ = 3;
			static const __i16 mInit0_ = 4;
			static const __i16 mInit1_ = 5;
			static const __i16 mStart0_ = 6;
			static const __i16 mStart1_ = 7;
			static const __i16 mRun_ = 8;
			static const __i16 mPause_ = 9;
			static const __i16 mStop_ = 10;
			static const __i16 mExit_ = 11;
		};
	public:
		bool runPreinit(const char * nPath, bool nConfigure = false);
		
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
		
	private:
		void runClear();

	public:
		InitService();
		~InitService();
		
	private:
		std::atomic<__i16> mInitType;
	};

}
