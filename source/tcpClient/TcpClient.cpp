#include "../Include.h"

#ifdef __TCPCLIENT__
namespace std {

#ifdef __CONSOLE__
	StringWriterPtr TcpClient::commandInfo(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		string className_(""); 
		__i32 classid_ = __classinfo<TcpClient>(className_);	
		stringWriter_.runString(className_, "className");
		stringWriter_.runInt32(classid_, "classId");
		stringWriter_.runString(mAddress, "address");
		stringWriter_.runString(mPort, "port");
		return stringWriter_;
	}
	
	StringWriterPtr TcpClient::commandReload(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		this->runLoad();
		stringWriter_.runString(mAddress, "address");
		stringWriter_.runString(mPort, "port");
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

	const char * TcpClient::streamName()
	{
		return "tcpAddress";
	}

	const char * TcpClient::streamUrl()
	{
		return "tcpAddress.xml";
	}

	bool TcpClient::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunLoad0.connect(boost::bind(&TcpClient::runLoad, this));
		initService_.m_tRunStart0.connect(boost::bind(&TcpClient::runStart, this));
	#ifdef __CONSOLE__
		this->registerCommand("info", std::bind(&TcpClient::commandInfo, this, _1));
		this->registerCommand("reload", std::bind(&TcpClient::commandReload, this, _1));
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
		
		SessionService sessionService_ = Singleton<SessionService>::instance();
		SessionPtr& session_ = sessionService_->getSession();
		
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
	
	static Preinit<TcpClient> sTcpClientPreinit;
}
#endif
