#pragma once

namespace std {

	class __funapi ClosedService : boost::noncopyable
	{
	public:
		void runClosedModule(const char * nClosedModuleName);
		
		ClosedService();
		~ClosedService();
		
	private:
		std::map<__i32, ClosedModulePtr> mClosedModules;
	};

}
