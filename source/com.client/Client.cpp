#include "../com.common/DefInc.h"
#include "../com.log/LogService.h"
#include "../com.init/InitService.h"
#include "../com.setting/SettingService.h"
#include "../com.ioservice/IoService.h"
#include "Client.h"

#ifdef __CLIENT__
namespace std {

	void Client::handleConnect(const boost::system::error_code& nError)
	{
		mConnectTimer->cancel();
		if (nError) {
			this->runStop();
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(nError.message()));
			return;
		}
		mSession->runStart();
	}

	void Client::handleConnectTimeout(const boost::system::error_code& nError)
	{
		this->runStop();
		LogService& logService = Singleton<LogService>::instance();
		logService.logError(log_1(nError.message()));
	}

	void Client::startConnect()
	{
		try {
			mConnectTimer->expires_from_now(boost::posix_time::seconds(Client::connect_timeout));
			mConnectTimer->async_wait(boost::bind(&Client::handleConnectTimeout, 
				shared_from_this(), boost::asio::placeholders::error));
			IoService& ioService_ = Singleton<IoService>::instance();
			asio::io_service& ioservice = ioService_.getIoService();
			asio::ip::tcp::resolver resolver_(ioservice);
			asio::ip::tcp::resolver::query query_(mAddress, mPort);
			asio::ip::tcp::resolver::iterator iterator_ = resolver_.resolve(query_);
			boost::asio::async_connect(mSession->getSocket(), iterator_,
				boost::bind(&Client::handleConnect, this,
				boost::asio::placeholders::error));
		} catch (boost::system::system_error& e) {
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(e.what()));
		}
	}

	const char * Client::streamName()
	{
		return "server";
	}

	const char * Client::streamUrl()
	{
		return "config/server.xml";
	}

	void Client::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunLoad.connect(boost::bind(&Client::runLoad, this));
		initService_.m_tRunStart.connect(boost::bind(&Client::runStart, this));
	}

	void Client::runLoad()
	{
		LogService& logService = Singleton<LogService>::instance();
		logService.logError(log_1("begin load client config!"));
		SettingService& settingService_ = Singleton<SettingService>::instance();
		settingService_.initUrlStream(this);
	}

	void Client::runStart()
	{
		LogService& logService = Singleton<LogService>::instance();
		logService.logError(log_1("client begin run start!"));

		IoService& ioService_ = Singleton<IoService>::instance();
		asio::io_service& ioservice = ioService_.getIoService();
		mSession.reset(new Session(ioservice));
		mConnectTimer.reset(new asio::deadline_timer(ioservice));
		this->startConnect();
	}

	void Client::runStop()
	{
		IoService& ioService = Singleton<IoService>::instance();
		ioService.runStop();
	}

	Client::Client()
		: mAddress("127.0.0.1")
		, mPort("8080")
	{
	}

	Client::~Client()
	{
		mAddress = "127.0.0.1";
		mPort = "8080";
	}

}
#endif
