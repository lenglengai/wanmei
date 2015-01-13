#pragma once

#include "Handle.h"

namespace std {

	class __funapi HandleService : public IService
	{
	public:
		void addContext(ContextPtr& nContext, const __i32 nIndex);
		
	private:
	#ifdef __CONSOLE__
		const StringWriterPtr commandInfo(const CommandArgs& nCommandArgs);
	#endif
	
	public:
	#ifdef __GAME__
		template<class __t>
		void headSerialize(__t& nT)
		{
			nT.runInt32(mHandleCount, "handleCount");
		}
		const char * streamName() const;
		const char * streamUrl() const;
	#endif
		
		bool runPreinit() OVERRIDE FINAL;
	#ifdef __GAME__
		bool runConfig() OVERRIDE FINAL;
	#endif
		bool initBegin() OVERRIDE FINAL;
		void starting() OVERRIDE FINAL;
		void stoping() OVERRIDE FINAL;
		
		HandleService();
		~HandleService();
		
	private:
		map<__i32, HandlePtr> mHandles;
		__i32 mHandleCount;
	};

}
