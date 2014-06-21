#pragma once

#include <boost/signals2.hpp>

namespace std {

	class InitService : boost::noncopyable
	{
	private:
		enum InitType_ : __i8
		{
			mInitTypeNone_ = 0,
			mInitTypePreinit_ = 1,
			mInitTypeLoad_ = 2,
			mInitTypeInit_ = 3,
			mInitTypeStart_ = 4,
			mInitTypeRun_ = 5,
			mInitTypeStop_ = 6,
			mInitTypeExit_ = 7
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
		InitType_ mInitType;
	};

}
