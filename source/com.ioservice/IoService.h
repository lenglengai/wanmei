#pragma once

#include <boost/asio.hpp>
#include <boost/thread.hpp>

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
		typedef shared_ptr<asio::io_service> IoServicePtr;
		typedef shared_ptr<asio::io_service::work> WorkPtr;
		boost::shared_ptr<asio::signal_set> mSignals;
		vector<IoServicePtr> mIoServices;
		vector<WorkPtr> mWork;
		size_t mNextIoService;
		__i32 mIoServiceCount;
	};
	template<class T>
	void IoService::headSerialize(T& nSerialize)
	{
		nSerialize.runInt32(mIoServiceCount, "ioServiceCount", 4);
	}

}
