#pragma once

#include "../../common/property/PropertySink.h"

#include "../packet/Session.h"

#ifdef __SERVERNET__
namespace std {

	class Server : public PropertySink
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize);
		const char * streamName();
		const char * streamUrl();
		void runPreinit();
		void runLoad();
		void runStart();

		Server();
		~Server();

	private:
		void handleAccept(const boost::system::error_code& nError);
		void startAccept();
		void runStop();

	private:
		boost::shared_ptr<asio::ip::tcp::acceptor> mAcceptor;
		SessionPtr mNewSession;
		string mAddress;
		string mPort;
	};
	template<class T>
	void Server::headSerialize(T& nSerialize)
	{
		nSerialize.runString(mAddress, "address", "127.0.0.1");
		nSerialize.runString(mPort, "port", "8080");
	}

}
#endif
