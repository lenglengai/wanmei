#pragma once

#ifdef __WITHMYSQL__
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
        mUpdate_,
		mQuery_,
    };
	
}
#endif
