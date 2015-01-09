#pragma once

#ifdef __WITHSQL__
namespace std {
	
	enum class SqlDeal_ : __i8
    {
        mNone_,
        mCreateFD_,
        mCreatePy_,
        mSelectFD_,
        mWhere_,
        mInsertFD_,
        mUpdateFD_,
        mInsertUpdateFD_,
		mQuery_,
		mEnd_
    };
	
}
#endif
