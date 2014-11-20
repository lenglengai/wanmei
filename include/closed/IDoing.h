#pragma once

namespace std {

	class __funapi IDoing : boost::noncopyable
	{
	public:
		virtual INumber runGetting(ClosedPtr& nClosed) = 0;
		virtual void runSetting(ClosedPtr& nClosed) = 0;
		virtual __i32 doingType() = 0;
	};
	typedef std::shared_ptr<IDoing> DoingPtr;

}
