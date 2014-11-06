#pragma once

#ifdef __WINDOW__
#pragma warning( push )
#pragma warning( disable : 4819 )
#endif

#include <boost/asio.hpp>

#ifdef __WINDOW__
#pragma warning( pop )
#endif

using namespace boost;

#ifdef __IOSERVICE__
namespace std {

	class __funapi IoService : boost::noncopyable
	{
	public:
		asio::io_service& getIoService();

		bool runPreinit();
		void runInit();
		void runStart();
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
		std::vector<WorkPtr> mWorks;
		std::size_t mNextIoService;
		__i32 mIoServiceCount;
	};

}
#endif
