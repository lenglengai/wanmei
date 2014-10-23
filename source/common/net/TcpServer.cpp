#include "../Common.h"

#ifdef __TCPSERVER__
namespace std {

	void TcpServer::handleAccept(const boost::system::error_code& nError)
	{
		if (nError) {
			this->runStop();
		#ifdef __LOG__
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(nError.message()));
		#endif
			return;
		}
		SessionPtr& session_ = (*mNewPlayer)->getSession();
		session_->openSession();
		startAccept();
	}

	void TcpServer::startAccept()
	{
		try {
			PlayerService& playerService_ = Singleton<PlayerService>::instance();
			PlayerPtr& player_ = playerService_.generatePlayer();
			mNewPlayer = &player_;
			PropertyMgrPtr propertyMgrPtr_ = std::dynamic_pointer_cast<PropertyMgr, Player>(player_);
            this->runCreate(propertyMgrPtr_);
			SessionPtr& session_ = player_->getSession();
			IoService& ioService_ = Singleton<IoService>::instance();
			session_.reset(new Session(ioService_.getIoService(), player_));
			mAcceptor->async_accept(session_->getSocket(),
				boost::bind(&TcpServer::handleAccept, this,
				boost::asio::placeholders::error));
		} catch (boost::system::system_error& e) {
		#ifdef __LOG__
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(e.what()));
		#endif
		}
	}

	const char * TcpServer::streamName()
	{
		return "tcpServer";
	}

	const char * TcpServer::streamUrl()
	{
		return "tcpServer.xml";
	}

	bool TcpServer::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunStart0.connect(boost::bind(&TcpServer::runStart, this));
		initService_.m_tRunStop.connect(boost::bind(&TcpServer::runStop, this));
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	#endif
		return true;
	}

	void TcpServer::runLoad()
	{
		ArchiveService& archiveService_ = Singleton<ArchiveService>::instance();
		archiveService_.xmlUrlStream(this);
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	#endif
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
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("fihish!"));
	#endif
	}

	void TcpServer::runStop()
	{
 		mAcceptor->close();
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("fihish!"));
	#endif
	}

	TcpServer::TcpServer()
		: mAddress("127.0.0.1")
		, mNewPlayer(nullptr)
		, mPort("8080")
	{
	}

	TcpServer::~TcpServer()
	{
		mAddress = "127.0.0.1";
		mNewPlayer = nullptr;
		mPort = "8080";
	}
	
	static Preinit<TcpServer> sTcpServerPreinit;

}
#endif
