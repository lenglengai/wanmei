#pragma once

#include <boost/atomic.hpp>
#include <boost/array.hpp>
#include <boost/date_time.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <deque>

#include "../com.block/WriteBlock.h"
#include "IPacket.h"

using namespace boost;

namespace std {

	class IPlayer;
	typedef boost::weak_ptr<IPlayer> PlayerWtr;
	typedef boost::shared_ptr<IPlayer> PlayerPtr;
	class Session : public boost::enable_shared_from_this<Session>, boost::noncopyable
	{
	public:
		enum { write_timeout = 90 };
		enum { read_timeout = 90 };

		void setPlayer(PlayerPtr& nPlayer);
		void runSend(PacketPtr& nPacket);
		asio::ip::tcp::socket& getSocket();
		void runStart();

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
		boost::asio::deadline_timer mReadTimer;
		boost::asio::deadline_timer mWriteTimer;
		boost::array<__i8, 1024> mReadBuffer;
		mutable atomic<bool> mSending;
		WriteBlockPtr mWriteBlockPtr;
		boost::shared_mutex mMutex;
		deque<PacketPtr> mPackets;
		ReadBlockPtr mReadBlock;
		asio::ip::tcp::socket mSocket;
		PlayerWtr mPlayer;
		bool mFirst;
	};
	typedef boost::weak_ptr<Session> SessionWtr;
	typedef boost::shared_ptr<Session> SessionPtr;

}
