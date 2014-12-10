#pragma once

#include <boost/array.hpp>
#include <boost/asio.hpp>

using namespace boost;

namespace std {

	struct SessionState_ 
	{
	 static const __i32 mClosed_ = 0;
	 static const __i32 mOpened_ = 1;
	};
	class Session : public std::enable_shared_from_this<Session>,  boost::noncopyable
	{
	public:
		enum { write_timeout = 150 };
		enum { read_timeout = 300 };

		bool runSend(PacketPtr& nPacket);
		asio::ip::tcp::socket& getSocket();
		void runStart();
		void runClose();
		void setPlayer(PlayerPtr& nPlayer);
		__i32 getSessionState();
		void openSession();

		explicit Session(asio::io_service& nIoService, PlayerPtr& nPlayer);
		~Session();

	private:
		void handleRead(const boost::system::error_code& nError, size_t nBytes);
		void handleReadTimeout(const boost::system::error_code& nError);
		void handleWrite(const boost::system::error_code& nError);
		void handleWriteTimeout(const boost::system::error_code& nError);
		void pushPacket(PacketPtr& nPacket);
		PacketPtr popPacket();
		void internalSend();

	private:
		atomic<__i32> mSessionState;
		asio::ip::tcp::socket mSocket;
		
		std::mutex mMutex;
		std::deque<PacketPtr> mPackets;
		std::atomic<bool> mSending;
		
		boost::asio::deadline_timer mReadTimer;
		boost::array<__i8, PACKETMAX> mReadBuffer;
		ReadBlockPtr mReadBlock;
		
		boost::asio::deadline_timer mWriteTimer;
		WriteBlockPtr mWriteBlockPtr;
		
		PlayerPtr * mPlayer;
	};
	typedef std::weak_ptr<Session> SessionWtr;
	typedef std::shared_ptr<Session> SessionPtr;
	
}

