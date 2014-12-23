#include "../Include.h"

#ifdef __TCPSERVER__
namespace std {

	void TcpServer::handleAccept(const boost::system::error_code& nError)
	{
		if (nError) {
			this->runStop();
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

	const char * TcpServer::streamName()
	{
		return "tcpAddress";
	}

	const char * TcpServer::streamUrl()
	{
		return "tcpAddress.xml";
	}

	bool TcpServer::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunLoad0.connect(boost::bind(&TcpServer::runLoad, this));
		initService_.m_tRunStart0.connect(boost::bind(&TcpServer::runStart, this));
		initService_.m_tRunStop.connect(boost::bind(&TcpServer::runStop, this));
		return true;
	}

	void TcpServer::runLoad()
	{
		ArchiveService& archiveService_ = Singleton<ArchiveService>::instance();
		archiveService_.loadStream(this);
	}

	void TcpServer::runStart()
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

	void TcpServer::runStop()
	{
 		mAcceptor->close();
	}

	TcpServer::TcpServer()
		: mAddress("127.0.0.1")
		, mNewSession(nullptr)
		, mPort("8080")
		, mDura(60000)
	{
	}

	TcpServer::~TcpServer()
	{
		mAddress = "127.0.0.1";
		mNewSession = nullptr;
		mPort = "8080";
	}
	
	static Preinit<TcpServer> sTcpServerPreinit;

}
#endif
