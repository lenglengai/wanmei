#pragma once

#ifdef __WITHDEBUG__
namespace std {
	
	class __funapi DebugService : public IService
	{
	public:
		bool runPreinit() OVERRIDE FINAL;
		
	public:
		DebugService();
		~DebugService();
	};

}
#endif
