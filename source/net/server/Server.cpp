#include "../../common/DefInc.h"

#include "../../service/log/LogService.h"
#include "../../service/init/InitService.h"
#include "../../service/setting/SettingService.h"
#include "../../service/ioservice/IoService.h"

#include "Server.h"

#ifdef __SERVER__

namespace std {

	void Server::handleAccept(const boost::system::error_code& nError)
	{
		if (nError) {
			this->runStop();
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(nError.message()));
			return;
		}
		mNewSession->runStart();
		startAccept();
	}

	void Server::startAccept()
	{
		try {
			IoService& ioService_ = Singleton<IoService>::instance();
			mNewSession.reset(new Session(ioService_.getIoService()));
			mAcceptor->async_accept(mNewSession->getSocket(),
				boost::bind(&Server::handleAccept, this,
				boost::asio::placeholders::error));
		} catch (boost::system::system_error& e) {
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(e.what()));
		}
	}

	const char * Server::streamName()
	{
		return "server";
	}

	const char * Server::streamUrl()
	{
		return "config/server.xml";
	}

	void Server::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunLoad.connect(boost::bind(&Server::runLoad, this));
		initService_.m_tRunStart.connect(boost::bind(&Server::runStart, this));
	}

	void Server::runLoad()
	{
		LogService& logService = Singleton<LogService>::instance();
		logService.logError(log_1("begin load server config!"));
		SettingService& settingService_ = Singleton<SettingService>::instance();
		settingService_.initUrlStream(this);
	}

	void Server::runStart()
	{
		LogService& logService = Singleton<LogService>::instance();
		logService.logError(log_1("server begin run start!"));

		IoService& ioService_ = Singleton<IoService>::instance();
		mAcceptor.reset(new asio::ip::tcp::acceptor(ioService_.getIoService()));

		asio::ip::tcp::resolver resolver_(mAcceptor->get_io_service());
		asio::ip::tcp::resolver::query query_(mAddress, mPort);
		asio::ip::tcp::endpoint endpoint_ = *resolver_.resolve(query_);
		mAcceptor->open(endpoint_.protocol());
		mAcceptor->set_option(asio::ip::tcp::acceptor::reuse_address(true));
		mAcceptor->bind(endpoint_);
		mAcceptor->listen();
		startAccept();
	}

	void Server::runStop()
	{
		IoService& ioService = Singleton<IoService>::instance();
		ioService.runStop();
	}

	Server::Server()
		: mAddress("127.0.0.1")
		, mPort("8080")
	{
	}

	Server::~Server()
	{
		mAddress = "127.0.0.1";
		mPort = "8080";
	}

}
#endif
