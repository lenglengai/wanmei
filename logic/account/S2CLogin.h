#pragma once

#ifdef __ACCOUNT__
namespace std {

	class AccountProtocol;
	class S2CLogin : public Packet<S2CLogin, AccountProtocol>, boost::noncopyable
	{
	public:
		static const char * sPacketName;
	public:
	#ifdef __CLIENT__
		bool handleRun(PlayerPtr& nPlayer);
	#endif
		bool runBlock(BlockPtr& nBlock);
		const char * getPacketName();
		bool isDefault();
		
		void setErrorCode(__i32 nErrorCode);
		__i32 getErrorCode();
		
		void setWireId(__i16 nWireId);
		__i16 getWireId();
		
		S2CLogin();
		S2CLogin(__i32 nErrorCode, __i16 nWireId);
		~S2CLogin();

	private:
		__i32 mErrorCode;
		__i16 mWireId;
	};
	typedef std::shared_ptr<S2CLogin> S2CLoginPtr;
	
}
#endif
