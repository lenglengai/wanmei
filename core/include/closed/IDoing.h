#pragma once

namespace std {

	class __funapi IDoing : boost::noncopyable
	{
	public:
		virtual void runClosed(PlayerPtr& nPlayer, ClosedPtr& nClosed,
			Values& nValues, ValueList * nValueList) = 0;
			
		virtual __i32 doingType() = 0;
	};

}
