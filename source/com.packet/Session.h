#pragma once

#include <boost/atomic.hpp>
#include <boost/array.hpp>
#include <boost/date_time.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <deque>
#include <ctime>

#include "../com.block/WriteBlock.h"
#include "../com.block/ReadBlock.h"
#include "IPacket.h"

using namespace boost;

namespace std {

	struct SessionState_ 
	{
	 static const __i32 mClosed_ = 0;
	 static const __i32 mOpened_ = 1;
	};
	class IPlayer;
	typedef boost::weak_ptr<IPlayer> PlayerWtr;
	typedef boost::shared_ptr<IPlayer> PlayerPtr;
	class Session : public boost::enable_shared_from_this<Session>, boost::noncopyable
	{
	public:
		enum { write_timeout = 90 };
		enum { read_timeout = 90 };

		void setSecond(__i32 nSecond);
		__i32 getSecond();
		void setPlayer(PlayerPtr& nPlayer);
		void runSend(PacketPtr& nPacket);
		asio::ip::tcp::socket& getSocket();
		void runStart();
		__i32 getSessionState();
		void openSession();

		Session(asio::io_service& nIoService);
		~Session();

	private:
		void handleRead(const boost::system::error_code& nError, size_t nBytes);
		void handleReadTimeout(const boost::system::error_code& nError);
		void handleWrite(const boost::system::error_code& nError);
		void handleWriteTimeout(const boost::system::error_code& nError);
		void pushPacket(PacketPtr& nPacket);
		PacketPtr popPacket();
		void internalSend();
		void runClose();

	private:
		mutable boost::atomic<__i32> mSessionState;
		boost::asio::deadline_timer mReadTimer;
		boost::asio::deadline_timer mWriteTimer;
		boost::array<__i8, 1024> mReadBuffer;
		mutable boost::atomic<bool> mSending;
		mutable boost::atomic<__i32> mSecond;
		WriteBlockPtr mWriteBlockPtr;
		boost::shared_mutex mMutex;
		deque<PacketPtr> mPackets;
		ReadBlockPtr mReadBlock;
		asio::ip::tcp::socket mSocket;
		PlayerWtr mPlayer;
	};
	typedef boost::weak_ptr<Session> SessionWtr;
	typedef boost::shared_ptr<Session> SessionPtr;

}
