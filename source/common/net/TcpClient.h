#pragma once

#include "../property/PropertySink.h"

#include "Session.h"

#ifdef __CLIENTNET__
namespace std {

	class TcpClient : public PropertySink
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
		SessionPtr& getSession();

		TcpClient();
		~TcpClient();

	private:
		void handleConnect(const boost::system::error_code& nError);
		void handleConnectTimeout(const boost::system::error_code& nError);
		void startConnect();
		void runStop();

	private:
		std::shared_ptr<asio::deadline_timer> mConnectTimer;
		SessionPtr mSession;
		std::string mAddress;
		std::string mPort;
	};
	typedef std::shared_ptr<TcpClient> ClientPtr;
	template<class T>
	void TcpClient::headSerialize(T& nSerialize)
	{
		nSerialize.runString(mAddress, "address", "127.0.0.1");
		nSerialize.runString(mPort, "port", "8080");
	}

}
#endif
