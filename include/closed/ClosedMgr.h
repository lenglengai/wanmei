#pragma once

namespace std {

	class __funapi ClosedMgr : boost::noncopyable
	{
	public:
		__i32 closedMgrId();
		
		ClosedMgr();
		~ClosedMgr();
		
	private:
		std::map<__i32, ClosedPtr> mCloseds;
		__i32 mClosedMgrId;
	};
	typedef std::shared_ptr<ClosedMgr> ClosedMgrPtr;

}
