#pragma once

namespace std {
	
	class IDbConnection : boost::noncopyable
	{
	public:
		void runActivate(bool nForce = false);
		void runConnect();
		void runDisconnect();
		void runRecycle();
		bool runGet();
		
	protected:
		virtual void internalConnect() = 0;
		virtual void internalDisconnect() = 0;
	
	public:
		explicit IDbConnection(IDataBase * nDataBase);
		virtual ~IDbConnection();
		
	private:
		IDataBase * mDataBase;
		__i64 mTimeStamp;
		bool mConnected;
		bool mBusy;
	}
	typedef std::shared_ptr<IDbConnection> DbConnectionPtr;
	
}
