#include "../Common.h"

#ifdef __TCPSERVER__
namespace std {

	void TcpServer::handleAccept(const boost::system::error_code& nError)
	{
		if (nError) {
			this->runStop();
		#ifdef __LOG__
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(nError.message()));
		#endif
			return;
		}
		SessionPtr& session_ = mNewPlayer->getSession();
		session_->openSession();
		startAccept();
	}

	void TcpServer::startAccept()
	{
		try {
			PlayerMgr& playerMgr_ = Singleton<PlayerMgr>::instance();
			mNewPlayer = playerMgr_.generatePlayer();
			PropertyMgrPtr propertyMgrPtr_ = std::dynamic_pointer_cast<PropertyMgr, Player>(mNewPlayer);
            this->runCreate(propertyMgrPtr_);
			SessionPtr& session_ = mNewPlayer->getSession();
			IoService& ioService_ = Singleton<IoService>::instance();
			session_.reset(new Session(ioService_.getIoService(), mNewPlayer));
			mAcceptor->async_accept(session_->getSocket(),
				boost::bind(&TcpServer::handleAccept, this,
				boost::asio::placeholders::error));
		} catch (boost::system::system_error& e) {
		#ifdef __LOG__
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(e.what()));
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
	#ifdef __LOG__
		LogService& logService = Singleton<LogService>::instance();
		logService.logInfo(log_1("TcpServer run runPreinit!"));
	#endif
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunStart0.connect(boost::bind(&TcpServer::runStart, this));
		initService_.m_tRunStop.connect(boost::bind(&TcpServer::runStop, this));
	#ifdef __LOG__
		logService.logInfo(log_1("TcpServer run runPreinit finish!"));
	#endif
		return true;
	}

	void TcpServer::runLoad()
	{
	#ifdef __LOG__
		LogService& logService = Singleton<LogService>::instance();
		logService.logError(log_1("TcpServer run runLoad!"));
	#endif
		ArchiveService& archiveService_ = Singleton<ArchiveService>::instance();
		archiveService_.xmlUrlStream(this);
	#ifdef __LOG__
		logService.logError(log_1("TcpServer run runLoad finish!"));
	#endif
	}

	void TcpServer::runStart()
	{
	#ifdef __LOG__
		LogService& logService = Singleton<LogService>::instance();
		logService.logError(log_1("TcpServer run runStart!"));
	#endif
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
		logService.logError(log_1("TcpServer run runStart fihish!"));
	#endif
	}

	void TcpServer::runStop()
	{
	#ifdef __LOG__
		LogService& logService = Singleton<LogService>::instance();
		logService.logError(log_1("TcpServer run runStop!"));
	#endif
 		mAcceptor->close();
	#ifdef __LOG__
		logService.logError(log_1("TcpServer run runStop fihish!"));
	#endif
	}

	TcpServer::TcpServer()
		: mAddress("127.0.0.1")
		, mPort("8080")
	{
	}

	TcpServer::~TcpServer()
	{
		mAddress = "127.0.0.1";
		mPort = "8080";
	}
	
	static Preinit<TcpServer> sTcpServerPreinit;

}
#endif
