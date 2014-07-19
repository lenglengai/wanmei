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
			static const __i16 mLoad0_ = 2;
			static const __i16 mLoad1_ = 3;
			static const __i16 mInit0_ = 4;
			static const __i16 mInit1_ = 5;
			static const __i16 mStart0_ = 6;
			static const __i16 mStart1_ = 7;
			static const __i16 mRun0_ = 8;
			static const __i16 mRun1_ = 9;
			static const __i16 mPause_ = 10;
			static const __i16 mStop_ = 11;
			static const __i16 mExit_ = 12;
		};
	public:
		void runPreinit(const string& nPath);
		
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

		boost::signals2::signal<void()> m_tRunRun0;
		void runRun0();

		boost::signals2::signal<void()> m_tRunRun1;
		void runRun1();

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
