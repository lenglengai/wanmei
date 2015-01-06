#include "../Include.h"

#ifdef __TCPCLIENT__
namespace std {

#ifdef __CONSOLE__
	const StringWriterPtr TcpClient::commandInfo(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		string className_(""); 
		__i32 classid_ = __classinfo<TcpClient>(className_);
		stringWriter_->runString(className_, "className");
		stringWriter_->runString(mAddress, "address");
		stringWriter_->runString(mPort, "port");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
	
	const StringWriterPtr TcpClient::commandReload(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		this->runLoad();
		stringWriter_->runString(mAddress, "address");
		stringWriter_->runString(mPort, "port");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}

	const StringWriterPtr TcpClient::commandReconnect(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		(*mSession)->runClose();
		chrono::milliseconds dura(200);
		this_thread::sleep_for(dura);
		this->reconnect();
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
#endif

	void TcpClient::handleConnect(const boost::system::error_code& nError)
	{
		mConnectTimer->cancel();
		if (nError) {
			this->runStop();
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(nError.message()));
			return;
		}
		(*mSession)->openSession();
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
			asio::ip::tcp::resolver resolver_(ioservice);
			asio::ip::tcp::resolver::query query_(mAddress, mPort);
			asio::ip::tcp::resolver::iterator iterator_ = resolver_.resolve(query_);
			boost::asio::async_connect((*mSession)->getSocket(), iterator_,
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
	
	void TcpClient::reconnect()
	{
		if ( (*mSession)->isClosed() ) {
			this->startConnect();
		}
	}

	const char * TcpClient::streamName() const
	{
		return "tcpAddress";
	}

	const char * TcpClient::streamUrl() const
	{
		return "tcpAddress.xml";
	}

	bool TcpClient::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunLoad0.connect(boost::bind(&TcpClient::runLoad, this));
		initService_.m_tRunStart0.connect(boost::bind(&TcpClient::runStart, this));
	#ifdef __CONSOLE__
		this->registerCommand("info", std::bind(&TcpClient::commandInfo, this, placeholders::_1));
		this->registerCommand("reload", std::bind(&TcpClient::commandReload, this, placeholders::_1));
		this->registerCommand("reconnect", std::bind(&TcpClient::commandReconnect, this, placeholders::_1));
	#endif
		return true;
	}

	void TcpClient::runLoad()
	{
		ArchiveService& archiveService_ = Singleton<ArchiveService>::instance();
		archiveService_.loadStream(this);
	}

	void TcpClient::runStart()
	{
		IoService& ioService_ = Singleton<IoService>::instance();
		asio::io_service& ioservice = ioService_.getIoService();
		mConnectTimer.reset(new asio::deadline_timer(ioservice));
		
		SessionService& sessionService_ = Singleton<SessionService>::instance();
		mSession = &(sessionService_.createSession());
		
		this->startConnect();
	}

	void TcpClient::runStop()
	{
		IoService& ioService = Singleton<IoService>::instance();
		ioService.runStop();
	}

	TcpClient::TcpClient()
		: mAddress("127.0.0.1")
		, mSession(nullptr)
		, mPort("8080")
	{
	}

	TcpClient::~TcpClient()
	{
		mAddress = "127.0.0.1";
		mSession = nullptr;
		mPort = "8080";
	}
	
	static Preinit0<TcpClient> sTcpClientPreinit;
}
#endif