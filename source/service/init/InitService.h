#pragma once

#include <boost/signals2.hpp>
#include <boost/atomic.hpp>

namespace std {

	class InitService : boost::noncopyable
	{
	private:
		struct InitType_
		{
			static const __i16 mNone_ = 0;
			static const __i16 mPreinit_ = 1;
			static const __i16 mLoad_ = 2;
			static const __i16 mInit_ = 3;
			static const __i16 mStart_ = 4;
			static const __i16 mRun_ = 5;
			static const __i16 mPause_ = 6;
			static const __i16 mStop_ = 7;
			static const __i16 mExit_ = 8;
		};
	public:
		void runPreinit(const string& nPath);
		
		boost::signals2::signal<void()> m_tRunLoad;
		void runLoad();
		
		boost::signals2::signal<void()> m_tRunInit;
		void runInit();

		boost::signals2::signal<void()> m_tRunStart;
		void runStart();

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
		
		InitService();
		~InitService();
	private:
		void runClear();
		
	private:
		mutable boost::atomic<__i16> mInitType;
	};

}
