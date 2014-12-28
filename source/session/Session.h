#pragma once

namespace std {

	struct SessionState_ 
	{
	 static const __i32 mClosed_ = 0;
	 static const __i32 mOpened_ = 1;
	};
	class Session : public enable_shared_from_this<Session>,  noncopyable
	{
	public:
		enum { write_timeout = 150 };
		enum { read_timeout = 300 };
		
	#ifdef __CLIENT__
		bool isSendTick();
	#endif

		bool runSend(PacketPtr& nPacket);
		
		void runStart();
		void runClose();
		
		const asio::ip::tcp::socket& getSocket() const;
		__i32 getSessionState() const;
		void openSession();
		
		__i32 getSessionId() const;
		void setSecond(const __i32 nSecond);
		__i32 getSecond() const;
		
		void setPlayer(PlayerPtr& nPlayer);
		PlayerPtr * getPlayer() const;
		bool isInLook() const;
		
		explicit Session(__i32 nSessionId, asio::io_service& nIoService);
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
		
		mutex mMutex;
		deque<PacketPtr> mPackets;
		atomic<bool> mSending;
		
		asio::deadline_timer mReadTimer;
		boost::array<__i8, PACKETMAX> mReadBuffer;
		ReadBlockPtr mReadBlock;
		
		asio::deadline_timer mWriteTimer;
		WriteBlockPtr mWriteBlock;
		
		PlayerPtr * mMainPlayer;
		PlayerPtr * mSecondPlayer;
		
		__i32 mSessionId;
		
		atomic<__i32> mSecond;
	#ifdef __CLIENT__
		atomic<__i64> mSendTick;
	#endif
	};
	
}

