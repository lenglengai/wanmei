#include "../com.common/DefInc.h"
#include "../com.log/LogService.h"
#include "ProtocolService.h"
#include "Session.h"
#include "IPlayer.h"

namespace std {

	void Session::setSecond(__i32 nSecond)
	{
		mSecond = nSecond;
	}

	__i32 Session::getSecond()
	{
		return mSecond;
	}

	void Session::setPlayer(PlayerPtr& nPlayer)
	{
		mPlayer = nPlayer;
	}

	void Session::runSend(PacketPtr& nPacket)
	{
		this->pushPacket(nPacket);
		if (false == mSending) {
			this->internalSend();
		}
	}

	void Session::runStart()
	{
		try {
			mReadTimer.expires_from_now(boost::posix_time::seconds(Session::read_timeout));
			mReadTimer.async_wait(boost::bind(&Session::handleReadTimeout, 
				shared_from_this(), boost::asio::placeholders::error));
			mSocket.async_read_some(boost::asio::buffer(mReadBuffer),
				boost::bind(&Session::handleRead, shared_from_this(),
				asio::placeholders::error,
				asio::placeholders::bytes_transferred));
		} catch (boost::system::system_error& e) {
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(e.what()));
		}
	}

	void Session::handleRead(const boost::system::error_code& nError, size_t nBytes)
	{
		mReadTimer.cancel();
		if (nError) {
			this->runClose();
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_2("read error", nError.message()));
			return;
		}
		std::cout << "[bytes haha]" << nBytes << std::endl;
		if (!mReadBlock->runPush(mReadBuffer.data(), nBytes)) {
			this->runClose();
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1("push error"));
			return;
		}
		ProtocolService& protocolService_ = Singleton<ProtocolService>::instance();
		if (!protocolService_.runReadBlock(mReadBlock, shared_from_this())) {
			this->runClose();
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1("runReadBlock error"));
			return;
		}
		mReadBuffer.assign(0);
		this->runStart();
	}

	void Session::handleReadTimeout(const boost::system::error_code& nError)
	{
		this->runClose();
		LogService& logService = Singleton<LogService>::instance();
		logService.logError(log_1(nError.message()));
	}

	void Session::handleWrite(const boost::system::error_code& nError)
	{
		mWriteTimer.cancel();
		if (nError) {
			this->runClose();
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(nError.message()));
			return;
		}
		this->internalSend();
	}

	void Session::handleWriteTimeout(const boost::system::error_code& nError)
	{
		this->runClose();
		LogService& logService = Singleton<LogService>::instance();
		logService.logError(log_1(nError.message()));
	}

	__i32 Session::getSessionState()
	{
		return mSessionState;
	}

	void Session::openSession()
	{
		mSessionState = SessionState_::mOpened_;
		this->runStart();
	}

	void Session::runClose()
	{
		mSessionState = SessionState_::mClosed_;
		if (mSocket.is_open()) {
			try {
				boost::system::error_code error_;
				mSocket.shutdown(asio::socket_base::shutdown_both, error_);
				mSocket.close(error_);
			} catch (boost::system::system_error& e) {
				LogService& logService = Singleton<LogService>::instance();
				logService.logError(log_1(e.what()));
			}
		}
	}

	void Session::pushPacket(PacketPtr& nPacket)
	{
		boost::shared_lock<boost::shared_mutex> writeLock(mMutex);
		mPackets.push_back(nPacket);
	}

	PacketPtr Session::popPacket()
	{
		PacketPtr packet_;
		boost::shared_lock<boost::shared_mutex> readLock(mMutex);
		if (mPackets.size() > 0) {
			packet_ = mPackets.front();
			mPackets.pop_front();
		}
		return packet_;
	}

	void Session::internalSend()
	{
		PacketPtr packet_ = this->popPacket();
		if (nullptr == packet_.get()) {
			mSending = false;
			return;
		}
		mWriteBlockPtr->runClear();
		BlockPtr blockPtr_ = mWriteBlockPtr;
		if (!packet_->runBlock(blockPtr_)) {
			this->runClose();
			return;
		}
		mWriteBlockPtr->runEnd();
		try {
			mWriteTimer.expires_from_now(boost::posix_time::seconds(Session::write_timeout));
			mWriteTimer.async_wait(boost::bind(&Session::handleWriteTimeout,
				shared_from_this(), boost::asio::placeholders::error));
			asio::async_write(mSocket, boost::asio::buffer(mWriteBlockPtr->getBuffer(), (mWriteBlockPtr->getLength())),
				boost::bind(&Session::handleWrite, shared_from_this(),
				asio::placeholders::error));
			mSending = true;
		}
		catch (boost::system::system_error& e) {
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(e.what()));
		}
	}

	asio::ip::tcp::socket& Session::getSocket()
	{
		return mSocket;
	}

	Session::Session(asio::io_service& nIoService)
		: mSocket(nIoService)
		, mReadBlock(new ReadBlock())
		, mWriteBlockPtr(new WriteBlock())
		, mReadTimer(nIoService)
		, mWriteTimer(nIoService)
		, mSending(false)
		, mSecond(0)
		, mSessionState(SessionState_::mClosed_)
	{
		mReadBuffer.fill(0);
	}

	Session::~Session()
	{
		mSessionState = SessionState_::mClosed_;
		mReadBuffer.fill(0);
		mSending = false;
		mSecond = 0;
	}

}
