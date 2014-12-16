#pragma once

namespace std {

	struct ERRORINT
	{
		static const __i16 NONE = 0;
		static const __i16 SUCESS = 1;
		static const __i16 HAVEUPDATE = 2;
		static const __i16 MUSTUPDATE = 3;
		static const __i16 SYSTEMMAINTAIN = 4;
		static const __i16 SERVERERROR = 5;
		static const __i16 SERVERCLOSED = 6;
		static const __i16 DBERROR = 7;
		static const __i16 END = 0;
	};

}
