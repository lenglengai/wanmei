#pragma once

#ifdef __WITHMYSQL__
namespace std {

    struct SqlFieldId_
    {
        static const __i8 mNone_ = 0;
        static const __i8 mPrimary_ = 1;
        static const __i8 mNotNull_ = 2;
        static const __i8 mUnique_ = 4;
        static const __i8 mBinary_ = 8;
        static const __i8 mUnsigned_ = 16;
        static const __i8 mZeroFill_ = 32;
        static const __i8 mAutoIncremet_ = 64;
    };
	
}
#endif
