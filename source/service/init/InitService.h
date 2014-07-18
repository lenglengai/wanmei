#pragma once

#include <boost/signals2.hpp>
#include <boost/atomic.hpp>

namespace std {

	class InitService : boost::noncopyable
	{
	private:
		struct InitType_
		{
			static const int mNone_ = 0;
			static const int mPreinit_ = 1;
			static const int mLoad0_ = 2;
			static const int mLoad1_ = 3;
			static const int mInit0_ = 4;
			static const int mInit1_ = 5;
			static const int mStart0_ = 6;
			static const int mStart1_ = 7;
			static const int mRun0_ = 8;
			static const int mRun1_ = 9;
			static const int mPause_ = 10;
			static const int mStop_ = 11;
			static const int mExit_ = 12;
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
		mutable boost::atomic<int> mInitType;
	};

}
