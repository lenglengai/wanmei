#pragma once

namespace std {

	class IDbQuery : boost::noncopyable
	{
	public:
		virtual __i8 getInt8() = 0;
		virtual __i16 getInt16() = 0;
		virtual __i32 getInt32() = 0;
		virtual __i64 getInt64() = 0;
		virtual float getFloat() = 0;
		virtual double getDouble() = 0;
		virtual string getString() = 0;
	};
	
}

