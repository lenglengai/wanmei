#include "../../common/DefInc.h"

#include "../../service/log/LogService.h"
#include "../../service/init/InitService.h"
#include "../../service/setting/SettingService.h"
#include "../../service/ioservice/IoService.h"

#include "Client.h"

#ifdef __CLIENTNET__
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
		mSession->openSession();
	}

	void Client::handleConnectTimeout(const boost::system::error_code& nError)
	{
		if (nError) {
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(nError.message()));
		}
		if (mConnectTimer->expires_at() <= asio::deadline_timer::traits_type::now()) {
			this->runStop();
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(nError.message()));
			mConnectTimer->expires_at(boost::posix_time::pos_infin);
		}
	}

	void Client::startConnect()
	{
		try {
			IoService& ioService_ = Singleton<IoService>::instance();
			asio::io_service& ioservice = ioService_.getIoService();
			asio::ip::tcp::resolver resolver_(ioservice);
			asio::ip::tcp::resolver::query query_(mAddress, mPort);
			asio::ip::tcp::resolver::iterator iterator_ = resolver_.resolve(query_);
			boost::asio::async_connect(mSession->getSocket(), iterator_,
				boost::bind(&Client::handleConnect, this,
				boost::asio::placeholders::error));
			mConnectTimer->expires_from_now(boost::posix_time::seconds(Client::connect_timeout));
			mConnectTimer->async_wait(boost::bind(&Client::handleConnectTimeout, 
				this, boost::asio::placeholders::error));
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
		initService_.m_tRunLoad0.connect(boost::bind(&Client::runLoad, this));
		initService_.m_tRunStart0.connect(boost::bind(&Client::runStart, this));
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
		PropertyMgrPtr propertyMgrPtr_ = boost::dynamic_pointer_cast<PropertyMgr, Session>(mSession);
		this->runCreate(propertyMgrPtr_);
		mConnectTimer.reset(new asio::deadline_timer(ioservice));
		this->startConnect();
	}

	void Client::runStop()
	{
		IoService& ioService = Singleton<IoService>::instance();
		ioService.runStop();
	}

	SessionPtr& Client::getSession()
	{
		return mSession;
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
