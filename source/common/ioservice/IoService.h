#pragma once

#include <boost/asio.hpp>
#include <thread>

using namespace boost;

namespace std {

	class IoService : boost::noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize);
		const char * streamName();
		const char * streamUrl();

		asio::io_service& getIoService();

		void runPreinit();
		void runLoad();
		void runStart();
		void runInit();
		void runStop();
		void runRun();

		IoService();
		~IoService();

	private:
		typedef std::shared_ptr<asio::io_service> IoServicePtr;
		typedef std::shared_ptr<asio::io_service::work> WorkPtr;
		std::shared_ptr<asio::signal_set> mSignals;
		std::vector<IoServicePtr> mIoServices;
		std::vector<WorkPtr> mWork;
		std::size_t mNextIoService;
		__i32 mIoServiceCount;
	};
	template<class T>
	void IoService::headSerialize(T& nSerialize)
	{
	#ifdef __CLIENT__
		nSerialize.runInt32(mIoServiceCount, "clientIoCount", 2);
	#endif
	#ifdef __SERVER__
		nSerialize.runInt32(mIoServiceCount, "serverIoCount", 4);
	#endif
	}

}
