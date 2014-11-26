#pragma once

namespace std {

	class __funapi ClosedService : boost::noncopyable
	{
	public:
		ClosedMgrPtr& getClosedMgr(__i32 nModule, __i32 nClosedMgr);
		
		ClosedService();
		~ClosedService();
		
	private:
		std::map<__i32, ClosedModulePtr> mClosedModules;
	};

}
