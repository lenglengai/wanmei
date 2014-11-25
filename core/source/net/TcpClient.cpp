#include "../../include/Include.h"

#ifdef __TCPCLIENT__
namespace std {

	void TcpClient::handleConnect(const boost::system::error_code& nError)
	{
		mConnectTimer->cancel();
		if (nError) {
			this->runStop();
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(nError.message()));
			return;
		}
		PlayerPtr& player_ = SingletonPtr<Player>::instance();
		SessionPtr& session_ = player_->getSession();
		session_->openSession();
	}

	void TcpClient::handleConnectTimeout(const boost::system::error_code& nError)
	{
		if (nError) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(nError.message()));
		}
		if (mConnectTimer->expires_at() <= asio::deadline_timer::traits_type::now()) {
			this->runStop();
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(nError.message()));
			mConnectTimer->expires_at(boost::posix_time::pos_infin);
		}
	}

	void TcpClient::startConnect()
	{
		try {
			IoService& ioService_ = Singleton<IoService>::instance();
			asio::io_service& ioservice = ioService_.getIoService();
			
			PlayerPtr& player_ = SingletonPtr<Player>::instance();
			PropertyMgrPtr propertyMgrPtr_ = std::dynamic_pointer_cast<PropertyMgr, Player>(player_); 
			this->runCreate(propertyMgrPtr_);
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
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(e.what()));
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
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunStart0.connect(boost::bind(&TcpClient::runStart, this));
		
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
		return true;
	}

	void TcpClient::runLoad()
	{
		ArchiveService& archiveService_ = Singleton<ArchiveService>::instance();
		archiveService_.xmlUrlStream(this);

		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}

	void TcpClient::runStart()
	{
		IoService& ioService_ = Singleton<IoService>::instance();
		asio::io_service& ioservice = ioService_.getIoService();
		PlayerPtr& player_ = SingletonPtr<Player>::instance();
		SessionPtr& session_ = player_->getSession();
		session_.reset(new Session(ioservice, player_));
		mConnectTimer.reset(new asio::deadline_timer(ioservice));
		this->startConnect();
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}

	void TcpClient::runStop()
	{
		IoService& ioService = Singleton<IoService>::instance();
		ioService.runStop();
		
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
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
