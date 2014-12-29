#pragma once

#ifdef __TCPCLIENT__
namespace std {

	class TcpClient : public IService
	{
	private:
		void handleConnect(const boost::system::error_code& nError);
		void handleConnectTimeout(const boost::system::error_code& nError);
		void startConnect();
		void reConnect();
		void runStop();
		
	private:
	#ifdef __CONSOLE__
		const StringWriterPtr commandInfo(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandReload(const CommandArgs& nCommandArgs);
	#endif
		
	public:
		enum { connect_timeout = 90 };
		template<class T>
		void headSerialize(T& nT)
		{
			nT.runString(mAddress, "address");
			nT.runString(mPort, "port");
		}
		const char * streamName() const;
		const char * streamUrl() const;
		bool runPreinit();
		void runLoad();
		void runStart();

		TcpClient();
		~TcpClient();

	private:
		shared_ptr<asio::deadline_timer> mConnectTimer;
		SessionPtr * mSession;
		string mAddress;
		string mPort;
	};
	typedef shared_ptr<TcpClient> ClientPtr;

}
#endif
