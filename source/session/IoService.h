#pragma once

namespace std {

	class __funapi IoService : public IService
	{
	public:
		asio::io_service& getIoService();
		
	private:
	#ifdef __CONSOLE__
		const StringWriterPtr commandInfo(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandReload(const CommandArgs& nCommandArgs);
	#endif
	
	public:
		template<class __t>
		void headSerialize(__t& nT)
		{
			nT.runInt32(mIoServiceCount, "ioServiceCount");
		}
		const char * streamName() const;
		const char * streamUrl() const;
		
		bool runPreinit() OVERRIDE FINAL;
		bool runConfig() OVERRIDE FINAL;
		bool initBegin() OVERRIDE FINAL;
		void startBegin() OVERRIDE FINAL;
		void stopBegin() OVERRIDE FINAL;
		void runing() OVERRIDE FINAL;
		void runClear() OVERRIDE FINAL;

		IoService();
		~IoService();
		
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
