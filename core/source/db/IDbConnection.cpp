#include "../../include/Include.h"

namespace std {
	
	void IDbConnection::runActivate(bool nForce)
	{
		if ( (!mConnected ) || nForce ) {
			this->runDisconnect();
			this->runConnect();
			return;
		}
		if (!mBusy) {
			TimeService& timeService_ = Singleton<TimeService>::instance();
			__i64 currentTime_ = timeService_.getLocalTime();
			if (currentTime_ > mTimeStamp) {
				this->runDisconnect();
				this->runConnect();
			}
		}
	}
	
	void IDbConnection::runConnect()
	{
		if (!mConnected) {
			internalConnect();
			TimeService& timeService_ = Singleton<TimeService>::instance();
			mTimeStamp = timeService_.getLocalTime();
			mTimeStamp += mDataBase->getMaxUsedSeconds();
			mConnected = true;
			mBusy = false;
		}
	}
	
	void IDbConnection::runDisconnect()
	{
		if (mConnected) {
			internalDisconnect();
			mConnected = false;
			mBusy = false;
			mTimeStamp = 0;
		}
	}
	
	void IDbConnection::runRecycle()
	{
		mBusy = false;
	}
	
	bool IDbConnection::runGet()
	{
		this->runActivate();
		if ( (!mBusy) && mConnected ) {
			mBusy = true;
			return true;
		}
		return false;
	}
	
	IDbConnection::IDbConnection(IDataBase * nDataBase)
		: mDataBase (nDataBase)
		, mBusy (false)
		, mConnected (false)
		, mTimeStamp (0)
	{
	}
	
	IDbConnection::~IDbConnection()
	{
		mConnected = false;
		mTimeStamp = 0;
		mBusy = false;
	}
	
}
