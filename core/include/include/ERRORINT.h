#pragma once

namespace std {

	struct ERRORINT
	{
		static const __i32 NONE = 0;
		static const __i32 SUCESS = 1;
		static const __i32 HAVEUPDATE = 2;
		static const __i32 MUSTUPDATE = 3;
		static const __i32 SYSTEMMAINTAIN = 4;
		static const __i32 SERVERERROR = 5;
		static const __i32 SERVERCLOSED = 6;
		static const __i32 END = 0;
	};

}
