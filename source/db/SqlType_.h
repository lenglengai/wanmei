#pragma once

#ifdef __WITHSQL__
namespace std {

    enum class SqlType_ : __i8
    {
		mNone_,
		mCreateDB_,
		mDropDB_,
		mSetDB_,
        mCreateTB_,
		mDropTB_,
        mSelect_,
        mInsert_,
		mReplace_,
        mDelete_,
        mUpdate_,
        mInsertUpdate_,
		mEnd_
    };
	
}
#endif
