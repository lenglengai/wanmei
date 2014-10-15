#include "../Common.h"

#ifdef __TCPCLIENT__
namespace std {

	void TcpClient::handleConnect(const boost::system::error_code& nError)
	{
		mConnectTimer->cancel();
		if (nError) {
			this->runStop();
		#ifdef __LOG__
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(nError.message()));
		#endif
			return;
		}
		PlayerPtr& player_ = SingletonPtr<Player>::instance();
		SessionPtr& session_ = player_->getSession();
		session_->openSession();
	}

	void TcpClient::handleConnectTimeout(const boost::system::error_code& nError)
	{
		if (nError) {
		#ifdef __LOG__
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(nError.message()));
		#endif
		}
		if (mConnectTimer->expires_at() <= asio::deadline_timer::traits_type::now()) {
			this->runStop();
		#ifdef __LOG__
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(nError.message()));
		#endif
			mConnectTimer->expires_at(boost::posix_time::pos_infin);
		}
	}

	void TcpClient::startConnect()
	{
		try {
			IoService& ioService_ = Singleton<IoService>::instance();
			asio::io_service& ioservice = ioService_.getIoService();
			
			PlayerPtr& player_ = SingletonPtr<Player>::instance();
			SessionPtr& session_ = player_->getSession();
		
			asio::ip::tcp::resolver resolver_(ioservice);
			asio::ip::tcp::resolver::query query_(mAddress, mPort);
			asio::ip::tcp::resolver::iterator iterator_ = resolver_.resolve(query_);
			boost::asio::async_connect(session_->getSocket(), iterator_,
				boost::bind(&TcpClient::handleConnect, this,
				boost::asio::placeholders::error));
			mConnectTimer->expires_from_now(boost::posix_time::seconds(TcpClient::connect_timeout));
			mConnectTimer->async_wait(boost::bind(&TcpClient::handleConnectTimeout, 
				this, boost::asio::placeholders::error));
		} catch (boost::system::system_error& e) {
		#ifdef __LOG__
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(e.what()));
		#endif
		}
	}

	const char * TcpClient::streamName()
	{
		return "tcpClient";
	}

	const char * TcpClient::streamUrl()
	{
		return "tcpClient.xml";
	}

	bool TcpClient::runPreinit()
	{
	#ifdef __LOG__
		LogService& logService = Singleton<LogService>::instance();
		logService.logInfo(log_1("TcpClient run runPreinit!"));
	#endif
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunStart0.connect(boost::bind(&TcpClient::runStart, this));
	#ifdef __LOG__
		logService.logInfo(log_1("TcpClient run runPreinit finish!"));
	#endif
		return true;
	}

	void TcpClient::runLoad()
	{
	#ifdef __LOG__
		LogService& logService = Singleton<LogService>::instance();
		logService.logInfo(log_1("TcpClient run runLoad!"));
	#endif
		ArchiveService& archiveService_ = Singleton<ArchiveService>::instance();
		archiveService_.xmlUrlStream(this);
	#ifdef __LOG__
		logService.logInfo(log_1("TcpClient run runLoad finish!"));
	#endif
	}

	void TcpClient::runStart()
	{
	#ifdef __LOG__
		LogService& logService = Singleton<LogService>::instance();
		logService.logInfo(log_1("TcpClient run runStart!"));
	#endif
		IoService& ioService_ = Singleton<IoService>::instance();
		asio::io_service& ioservice = ioService_.getIoService();
		PlayerPtr& player_ = SingletonPtr<Player>::instance();
		SessionPtr& session_ = player_->getSession();
		session_.reset(new Session(ioservice), player_);
		mConnectTimer.reset(new asio::deadline_timer(ioservice));
		this->startConnect();
	#ifdef __LOG__
		logService.logInfo(log_1("TcpClient run runStart finish!"));
	#endif
	}

	void TcpClient::runStop()
	{
	#ifdef __LOG__
		LogService& logService = Singleton<LogService>::instance();
		logService.logInfo(log_1("TcpClient run runStop!"));
	#endif
		IoService& ioService = Singleton<IoService>::instance();
		ioService.runStop();
	#ifdef __LOG__
		logService.logInfo(log_1("TcpClient run runStop finish!"));
	#endif
	}

	TcpClient::TcpClient()
		: mAddress("127.0.0.1")
		, mPort("8080")
	{
	}

	TcpClient::~TcpClient()
	{
		mAddress = "127.0.0.1";
		mPort = "8080";
	}
	
	static Preinit<TcpClient> sTcpClientPreinit;
}
#endif
