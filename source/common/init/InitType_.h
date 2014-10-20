#pragma once

namespace std {
	
	enum class InitType_ : __i16
	{
		mNone_,
		mPreinit_,
		mLoad0_,
		mLoad1_,
		mInit0_,
		mInit1_,
		mStart0_,
		mStart1_,
		mRun_,
		mPause_,
		mStop_,
		mExit_
	};
	
}
