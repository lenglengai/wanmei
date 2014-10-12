#include "../DefInc.h"

#include "../log/LogService.h"
#include "../init/InitService.h"
#include "ProtocolService.h"
#include "Session.h"
#include "ITourist.h"

#ifdef __NET__
namespace std {
	
	void Session::setTourist(TouristPtr& nTourist)
	{
		mTourist = nTourist;
	}

	bool Session::runSend(PacketPtr& nPacket)
	{
		InitService& initService_ = Singleton<InitService>::instance();
		if ( (initService_.isPause()) ||
			(SessionState_::mClosed_ == mSessionState) ) {
			return false;
		}
		this->pushPacket(nPacket);
		nPacket->runInit();
		if (false == mSending) {
			this->internalSend();
		}
		return true;
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
		#ifdef __LOG__
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(e.what()));
		#endif
		}
	}

	void Session::handleRead(const boost::system::error_code& nError, size_t nBytes)
	{
		mReadTimer.cancel();
		if (nError) {
			this->runClose();
		#ifdef __LOG__
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_2("read message error", nError.message()));
		#endif
			return;
		}
		BlockPushType_ blockPushType_ = mReadBlock->runPush(mReadBuffer.data(), nBytes);
		if (mBlockPushTypeError_ == blockPushType_) {
			this->runClose();
		#ifdef __LOG__
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1("block push error"));
		#endif
			return;
		}
		if (mBlockPushTypeLength_ == blockPushType_) return;
		ProtocolService& protocolService_ = Singleton<ProtocolService>::instance();
		if (!protocolService_.runReadBlock(mReadBlock, shared_from_this())) {
			this->runClose();
		#ifdef __LOG__
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1("runReadBlock error"));
		#endif
			return;
		}
		mReadBlock->endPush();
		mReadBuffer.assign(0);
		this->runStart();
	}

	void Session::handleReadTimeout(const boost::system::error_code& nError)
	{
		if (nError) {
		#ifdef __LOG__
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(nError.message()));
		#endif
		}
		if (mReadTimer.expires_at() <= asio::deadline_timer::traits_type::now()) {
			this->runClose();
		#ifdef __LOG__
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(nError.message()));
		#endif
			mReadTimer.expires_at(boost::posix_time::pos_infin);
		}
	}

	void Session::handleWrite(const boost::system::error_code& nError)
	{
		mWriteTimer.cancel();
		if (nError) {
			this->runClose();
		#ifdef __LOG__
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(nError.message()));
		#endif
			return;
		}
		this->internalSend();
	}

	void Session::handleWriteTimeout(const boost::system::error_code& nError)
	{
		if (nError) {
		#ifdef __LOG__
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(nError.message()));
		#endif
		}
		if (mWriteTimer.expires_at() <= asio::deadline_timer::traits_type::now()) {
			this->runClose();
		#ifdef __LOG__
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(nError.message()));
		#endif
			mWriteTimer.expires_at(boost::posix_time::pos_infin);
		}
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
			#ifdef __LOG__
				LogService& logService = Singleton<LogService>::instance();
				logService.logError(log_1(e.what()));
			#endif
			}
		}
	}

	void Session::pushPacket(PacketPtr& nPacket)
	{
		std::lock_guard<std::mutex> lock_(mMutex);
		mPackets.push_back(nPacket);
	}

	PacketPtr Session::popPacket()
	{
		PacketPtr packet_;
		std::lock_guard<std::mutex> lock_(mMutex);
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
		if (!packet_->runHeader(blockPtr_)) {
			this->runClose();
			return;
		}
		if (!packet_->runBlock(blockPtr_)) {
			this->runClose();
			return;
		}
		mWriteBlockPtr->runEnd();
		try {
			mWriteTimer.expires_from_now(boost::posix_time::seconds(Session::write_timeout));
			mWriteTimer.async_wait(boost::bind(&Session::handleWriteTimeout,
				shared_from_this(), boost::asio::placeholders::error));
			asio::async_write(mSocket, boost::asio::buffer(mWriteBlockPtr->getBuffer(), (mWriteBlockPtr->getTotal())),
				boost::bind(&Session::handleWrite, shared_from_this(),
				asio::placeholders::error));
			mSending = true;
		}
		catch (boost::system::system_error& e) {
		#ifdef __LOG__
			LogService& logService = Singleton<LogService>::instance();
			logService.logError(log_1(e.what()));
		#endif
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
		, mSessionState(SessionState_::mClosed_)
	{
		mReadBuffer.fill(0);
		mPackets.clear();
	}

	Session::~Session()
	{
		mSessionState = SessionState_::mClosed_;
		mReadBuffer.fill(0);
		mSending = false;
		mPackets.clear();
	}

}
#endif
