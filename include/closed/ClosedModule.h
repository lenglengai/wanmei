#pragma once

namespace std {

	class __funapi ClosedModule : boost::noncopyable
	{
	public:
		ClosedModule();
		~ClosedModule();
		
	private:
		std::map<__i32, ClosedMgrPtr> mClosedMgrs;
	};
	typedef std::shared_ptr<ClosedModule> ClosedModulePtr;

}
