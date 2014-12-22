#pragma once

namespace std {

	class __funapi IoService : public IService
	{
	public:
		asio::io_service& getIoService();
		
	private:
	#ifdef __CONSOLE__
		StringWriterPtr commandInfo(const CommandArgs& nCommand);
		StringWriterPtr commandReload(const CommandArgs& nCommand);
	#endif
	
	public:
		template<class __t>
		void headSerialize(__t& nT)
		{
			nT.runInt32(mIoServiceCount, "ioServiceCount");
		}
		const char * streamName();
		const char * streamUrl();
		
		bool runPreinit();
		void runLoad();
		void runInit();
		void runStart();
		void runStop();
		void runRun();

		IoService();
		~IoService();
		
	private:
		void runClear();

	private:
		typedef shared_ptr<asio::io_service> IoServicePtr;
		typedef shared_ptr<asio::io_service::work> WorkPtr;
		shared_ptr<asio::signal_set> mSignals;
		vector<IoServicePtr> mIoServices;
		vector<WorkPtr> mWorks;
		size_t mNextIoService;
		__i32 mIoServiceCount;
	};

}
