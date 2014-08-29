#pragma once

#include <boost/array.hpp>
#include <boost/asio.hpp>

#include <atomic>
#include <deque>
#include <mutex>

#include "../property/PropertyMgr.h"

#include "IPacket.h"
#include "WriteBlock.h"
#include "ReadBlock.h"


using namespace boost;

#ifdef __NET__
namespace std {

	struct SessionState_ 
	{
	 static const __i32 mClosed_ = 0;
	 static const __i32 mOpened_ = 1;
	};
	class ITourist;
	typedef std::weak_ptr<ITourist> TouristWtr;
	typedef std::shared_ptr<ITourist> TouristPtr;
	class Session : public PropertyMgr, public std::enable_shared_from_this<Session>
	{
	public:
		enum { write_timeout = 90 };
		enum { read_timeout = 90 };

		void setTourist(TouristPtr& nTourist);
		bool runSend(PacketPtr& nPacket);
		asio::ip::tcp::socket& getSocket();
		void runStart();
		void runClose();
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

	private:
		mutable atomic<__i32> mSessionState;
		boost::asio::deadline_timer mReadTimer;
		boost::asio::deadline_timer mWriteTimer;
		boost::array<__i8, PACKETMAX> mReadBuffer;
		volatile atomic<bool> mSending;
		WriteBlockPtr mWriteBlockPtr;
		asio::ip::tcp::socket mSocket;
		deque<PacketPtr> mPackets;
		ReadBlockPtr mReadBlock;
		TouristWtr mTourist;
		std::mutex mMutex;
	};

}
#endif
