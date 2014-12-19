#pragma once

namespace std {

	enum class Error_ : __i16
	{
		mBegin_ = 0,
		mSucess_ = 1,
		mHaveUpdate_ = 2,
		mMustUpdate_ = 3,
		mMaintain_ = 4,
		mError_ = 5,
		mDbError_ = 6,
		mEnd_
	};

}
