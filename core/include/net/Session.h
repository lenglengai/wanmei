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
		enum { write_timeout = 90 };
		enum { read_timeout = 90 };

		bool runSend(PacketPtr& nPacket);
		asio::ip::tcp::socket& getSocket();
		void runStart();
		void runClose();
		__i32 getSessionState();
		void openSession();

		Session(asio::io_service& nIoService, PlayerPtr& nPlayer);
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
		boost::asio::deadline_timer mReadTimer;
		boost::asio::deadline_timer mWriteTimer;
		boost::array<__i8, PACKETMAX> mReadBuffer;
		std::atomic<bool> mSending;
		WriteBlockPtr mWriteBlockPtr;
		asio::ip::tcp::socket mSocket;
		deque<PacketPtr> mPackets;
		ReadBlockPtr mReadBlock;
		PlayerPtr& mPlayer;
		std::mutex mMutex;
	};
	typedef std::weak_ptr<Session> SessionWtr;
	typedef std::shared_ptr<Session> SessionPtr;
}

