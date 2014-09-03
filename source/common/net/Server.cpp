#include "../DefInc.h"

#include "../log/LogService.h"
#include "../init/InitService.h"
#include "../setting/SettingService.h"
#include "../archive/ArchiveService.h"
#include "../ioservice/IoService.h"

#include "Server.h"

#ifdef __SERVERNET__
namespace std {

	void Server::handleAccept(const boost::system::error_code& nError)
	{
		if (nError) {
			this->runStop();
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(nError.message()));
			return;
		}
		mNewSession->openSession();
		startAccept();
	}

	void Server::startAccept()
	{
		try {
			IoService& ioService_ = Singleton<IoService>::instance();
			mNewSession.reset(new Session(ioService_.getIoService()));
			PropertyMgrPtr propertyMgrPtr_ = std::dynamic_pointer_cast<PropertyMgr, Session>(mNewSession);
			this->runCreate(propertyMgrPtr_);
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
		return "server.xml";
	}

	void Server::runPreinit()
	{
		ArchiveService& archiveService_ = Singleton<ArchiveService>::instance();
		archiveService_.m_tRunConfigure.connect(boost::bind(&Server::runLoad, this));

		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunStart0.connect(boost::bind(&Server::runStart, this));
	}

	void Server::runLoad()
	{
		LogService& logService = Singleton<LogService>::instance();
		logService.logError(log_1("begin load server config!"));
		ArchiveService& archiveService_ = Singleton<ArchiveService>::instance();
		archiveService_.initUrlStream(this);
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
