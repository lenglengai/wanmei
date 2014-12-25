#pragma once

#ifdef __TCPSERVER__
namespace std {

	class TcpServer : public IService
	{
	private:
		void handleAccept(const boost::system::error_code& nError);
		void startAccept();
		void runStop();
		
	private:
	#ifdef __CONSOLE__
		const StringWriterPtr commandInfo(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandReload(const CommandArgs& nCommandArgs);
	#endif
	
	public:
		template<class T>
		void headSerialize(T& nSerialize)
		{
			nSerialize.runString(mAddress, "address", "127.0.0.1");
			nSerialize.runString(mPort, "port", "8080");
		}
		const char * streamName() const;
		const char * streamUrl() const;
		bool runPreinit();
		void runLoad();
		void runStart();

		TcpServer();
		~TcpServer();

	private:
		shared_ptr<asio::ip::tcp::acceptor> mAcceptor;
		chrono::milliseconds mDura;
		SessionPtr * mNewSession;
		string mAddress;
		string mPort;
	};

}
#endif
