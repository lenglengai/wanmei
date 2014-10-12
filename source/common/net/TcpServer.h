#pragma once

#include "../property/PropertySink.h"

#include "Session.h"

#ifdef __SERVERNET__
namespace std {

	class TcpServer : public PropertySink
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize)
		{
			nSerialize.runString(mAddress, "address", "127.0.0.1");
			nSerialize.runString(mPort, "port", "8080");
		}
		const char * streamName();
		const char * streamUrl();
		bool runPreinit();
		void runLoad();
		void runStart();

		TcpServer();
		~TcpServer();

	private:
		void handleAccept(const boost::system::error_code& nError);
		void startAccept();
		void runStop();

	private:
		std::shared_ptr<asio::ip::tcp::acceptor> mAcceptor;
		SessionPtr mNewSession;
		string mAddress;
		string mPort;
	};

}
#endif
