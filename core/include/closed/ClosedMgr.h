#pragma once

namespace std {

	class __funapi ClosedMgr : boost::noncopyable
	{
	public:
		std::map<__i32, ClosedsPtr>& getCloseds();
		__i32 closedMgrId();
		
	private:
		void runClear();
		
	public:
		ClosedMgr();
		~ClosedMgr();
		
	private:
		std::map<__i32, ClosedsPtr> mCloseds;
		__i32 mClosedMgrId;
	};
	typedef std::shared_ptr<ClosedMgr> ClosedMgrPtr;

}
