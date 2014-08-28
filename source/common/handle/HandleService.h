#pragma once

#include "Handle.h"

#ifdef __HANDLE__
namespace std {

	class __funapi HandleService : boost::noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize)
		{
			nSerialize.runInt32(mHandleCount, "handleCount", 2);
		}

		const char * streamName();
		const char * streamUrl();
		void addContext(ContextPtr& nContext, __i32 nIndex);
		int getHandleCount();
		void runPreinit();
		void runLoad();
		void runInit();
		void runStart();
		void runStop();

		HandleService();
		~HandleService();

	private:
		std::map<int, HandlePtr> mHandles;
		__i32 mHandleCount;
	};

}
#endif
