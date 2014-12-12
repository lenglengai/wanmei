#pragma once

#ifdef __TCPCLIENT__
namespace std {

	class TcpClient : public PropertySink
	{
	public:
		enum { connect_timeout = 90 };
		template<class T>
		void headSerialize(T& nSerialize)
		{
			nSerialize.runString(mAddress, "address");
			nSerialize.runString(mPort, "port");
		}
		const char * streamName();
		const char * streamUrl();
		bool runPreinit();
		void runLoad();
		void runStart();

		TcpClient();
		~TcpClient();

	private:
		void handleConnect(const boost::system::error_code& nError);
		void handleConnectTimeout(const boost::system::error_code& nError);
		void startConnect();
		void runStop();

	private:
		std::shared_ptr<asio::deadline_timer> mConnectTimer;
		std::string mAddress;
		std::string mPort;
	};
	typedef std::shared_ptr<TcpClient> ClientPtr;

}
#endif
