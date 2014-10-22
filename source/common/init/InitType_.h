#pragma once

namespace std {
	
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
	
}
