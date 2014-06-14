#pragma once

namespace std {

	struct ERRORINT
	{
		static const __i32 NONE = 0;
		static const __i32 SUCESS = 1;
		static const __i32 HAVEUPDATE = 2;
		static const __i32 MUSTUPDATE = 3;
		static const __i32 SYSTEM = 4;
		static const __i32 SERVERID = 5;
		static const __i32 CLOSED = 6;
	};

}
