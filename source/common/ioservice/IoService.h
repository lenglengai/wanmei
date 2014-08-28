#pragma once

#include <boost/asio.hpp>
#include <thread>

using namespace boost;

#ifdef __IOSERVICE__
namespace std {

	class __funapi IoService : boost::noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize)
		{
			nSerialize.runInt32(mIoServiceCount, "IoCount", 2);
		}
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
		void runClear();

	private:
		typedef std::shared_ptr<asio::io_service> IoServicePtr;
		typedef std::shared_ptr<asio::io_service::work> WorkPtr;
		std::shared_ptr<asio::signal_set> mSignals;
		std::vector<IoServicePtr> mIoServices;
		std::vector<WorkPtr> mWork;
		std::size_t mNextIoService;
		__i32 mIoServiceCount;
	};

}
#endif
