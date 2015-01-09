#include "../Include.h"
#include "IoService.h"
#include "TcpServer.h"

#ifdef __TCPSERVER__
namespace std {
#ifdef __CONSOLE__
	const StringWriterPtr TcpServer::commandInfo(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		string className_(""); 
		__i32 classid_ = __classinfo<TcpServer>(className_);
		stringWriter_->runString(className_, "className");
		stringWriter_->runString(mAddress, "address");
		stringWriter_->runString(mPort, "port");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
	
	const StringWriterPtr TcpServer::commandReload(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		this->runConfig();
		stringWriter_->runString(mAddress, "address");
		stringWriter_->runString(mPort, "port");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
#endif

	void TcpServer::handleAccept(const boost::system::error_code& nError)
	{
		if (nError) {
			this->stopEnd();
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(nError.message()));
			return;
		}
		(*mNewSession)->openSession();
		startAccept();
	}

	void TcpServer::startAccept()
	{
		try {
			SessionService& sessionService_ = Singleton<SessionService>::instance();
			mNewSession = &(sessionService_.createSession());
			mAcceptor->async_accept((*mNewSession)->getSocket(),
				boost::bind(&TcpServer::handleAccept, this,
				boost::asio::placeholders::error));
		} catch (boost::system::system_error& e) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(e.what()));
		}
	}

	const char * TcpServer::streamName() const
	{
		return "tcpAddress";
	}

	const char * TcpServer::streamUrl() const
	{
		return "tcpAddress.xml";
	}

	bool TcpServer::runPreinit()
	{
	#ifdef __CONSOLE__
		this->registerCommand("info", std::bind(&TcpServer::commandInfo, this, placeholders::_1));
		this->registerCommand("reload", std::bind(&TcpServer::commandReload, this, placeholders::_1));
	#endif
		return true;
	}

	void TcpServer::runConfig()
	{
		ArchiveService& archiveService_ = Singleton<ArchiveService>::instance();
		archiveService_.loadStream(this);
	}

	void TcpServer::startBegin()
	{
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

	void TcpServer::stopEnd()
	{
 		mAcceptor->close();
	}

	TcpServer::TcpServer()
		: mAddress("127.0.0.1")
		, mNewSession(nullptr)
		, mPort("8080")
	{
	}

	TcpServer::~TcpServer()
	{
		mAddress = "127.0.0.1";
		mNewSession = nullptr;
		mPort = "8080";
	}
	
	static Service<TcpServer> sTcpServer;

}
#endif
