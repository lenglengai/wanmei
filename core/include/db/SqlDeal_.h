#pragma once

namespace std {
	
	enum class SqlDeal_ : __i8
    {
        mNone_,
        mCreate_,
        mPrimary_,
        mSelect_,
        mWhere_,
        mInsert_,
        mInsertUpdate_,
        mInsertUpdateE_,
        mInsertUpdateEx_,
        mUpdate_,
        mUpdateSelect_,
        mUpdateWhen_,
        mUpdateThen_,
    };
	
}
