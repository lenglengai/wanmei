#pragma once

namespace std {
	
	class Closed
	{
	public:
		__i32 getClosedType();
		
		Closed();
		virtual ~Closed();
		
	private:
		__i32 mClosedType;
		__i32 mClosedId;
	};
	
}
