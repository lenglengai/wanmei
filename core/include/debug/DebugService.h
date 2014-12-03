#pragma once

#ifdef __WITHDEBUG__
namespace std {
	
	class __funapi DebugService : boost::noncopyable
	{
	public:
		bool runPreinit();
		
	public:
		DebugService();
		~DebugService();
	};

}
#endif
