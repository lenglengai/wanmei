#pragma once

#include "Handle.h"

namespace std {

	class HandleService : boost::noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize);
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

	template<class T>
	void HandleService::headSerialize(T& nSerialize)
	{
	#ifdef __CLIENT__
		nSerialize.runInt32(mHandleCount, "clientHandleCount", 2);
	#endif
	#ifdef __SERVER__
		nSerialize.runInt32(mHandleCount, "serverHandleCount", 4);
	#endif
	}

}
