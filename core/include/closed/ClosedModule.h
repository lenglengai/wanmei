#pragma once

namespace std {

	class __funapi ClosedModule : boost::noncopyable
	{
	public:
		ClosedMgrPtr& getClosedMgr(__i32 nClosedMgr);
		ClosedModule();
		~ClosedModule();
		
	private:
		std::map<__i32, ClosedMgrPtr> mClosedMgrs;
	};
	typedef std::shared_ptr<ClosedModule> ClosedModulePtr;

}
