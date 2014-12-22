#pragma once

namespace std {

	class __funapi HandleService : public IService
	{
	public:
		void addContext(ContextPtr& nContext, __i32 nIndex);
		
	private:
	#ifdef __CONSOLE__
		StringWriterPtr commandInfo(const CommandArgs& nCommand);
		StringWriterPtr commandReload(const CommandArgs& nCommand);
	#endif
	public:
		template<class __t>
		void headSerialize(__t& nT)
		{
			nT.runInt32(mHandleCount, "handleCount");
		}
		const char * streamName();
		const char * streamUrl();
		
		bool runPreinit();
		void runLoad();
		void runInit();
		void runStart();
		void runStop();
		
		HandleService();
		~HandleService();
		
	private:
		map<__i32, HandlePtr> mHandles;
		__i32 mHandleCount;
	};

}
