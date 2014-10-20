#pragma once

#ifdef __ACCOUNT__
namespace std {

	class LoginProtocol;
	class S2CLogin : public Packet<S2CLogin, LoginProtocol>, boost::noncopyable
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
	
		S2CLogin();
		S2CLogin(__i32 nErrorCode);
		~S2CLogin();

	private:
		__i32 mErrorCode;
	};
	typedef std::shared_ptr<S2CLogin> S2CLoginPtr;
	
}
#endif
