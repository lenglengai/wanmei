#pragma once

#include "Handle.h"

#ifdef __HANDLE__
namespace std {

	class __funapi HandleService : boost::noncopyable
	{
	public:
		void addContext(ContextPtr& nContext, __i32 nIndex);
		__i32 getHandleCount();
		void runPreinit();
		void runInit();
		void runStart();
		void runStop();

		HandleService();
		~HandleService();

	private:
		std::map<__i32, HandlePtr> mHandles;
		__i32 mHandleCount;
	};

}
#endif
