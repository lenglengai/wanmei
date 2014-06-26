#pragma once

#ifdef __CLIENT__
#include "../com.packet/Session.h"

namespace std {

	class Client : boost::noncopyable
	{
	public:
		enum { connect_timeout = 90 };
		template<class T>
		void headSerialize(T& nSerialize);
		const char * streamName();
		const char * streamUrl();
		void runPreinit();
		void runLoad();
		void runStart();

		Client();
		~Client();

	private:
		void handleConnect(const boost::system::error_code& nError);
		void handleConnectTimeout(const boost::system::error_code& nError);
		void startConnect();
		void runStop();

	private:
		boost::shared_ptr<asio::deadline_timer> mConnectTimer;
		SessionPtr mSession;
		std::string mAddress;
		std::string mPort;
	};
	template<class T>
	void Client::headSerialize(T& nSerialize)
	{
		nSerialize.runString(mAddress, "address", "127.0.0.1");
		nSerialize.runString(mPort, "port", "8080");
	}

}
#endif
