#pragma once

namespace std {

	class __funapi IDoing : boost::noncopyable
	{
	public:
		virtual void runDoing(ClosedPtr& nClosed, ValueList& nValueList) = 0;
		virtual __i32 doingType() = 0;
	};
	typedef std::shared_ptr<IDoing> DoingPtr;

}
