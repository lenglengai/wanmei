﻿#pragma once

#ifdef __WITHMYSQL__
namespace std {

    enum class SqlType_ : __i8
    {
		mDropDB_,
		mSetDB_,
		mDataBase_,
        mCreate_,
        mSelect_,
        mInsert_,
        mInsertUpdate_,
        mUpdate_,
        mDelete_,
    };
	
}
#endif