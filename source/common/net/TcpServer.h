#pragma once

#ifdef __TCPSERVER__
namespace std {

	class TcpServer
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
		PlayerPtr mNewPlayer;
		string mAddress;
		string mPort;
	};

}
#endif
