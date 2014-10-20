#pragma once

#ifdef __ACCOUNT__
namespace std {

	class LoginProtocol;
	class C2SLogin : public Packet<C2SLogin, LoginProtocol, false>, boost::noncopyable
	{
	public:
		static const char * sPacketName;
	public:
	#ifdef __SERVER__
		bool handleRun(PlayerPtr& nPlayer);
	#endif
		bool runBlock(BlockPtr& nBlock);
		void setPlayerName(std::string& nPlayerName);
		std::string& getPlayerName();
		void setPassward(__i32 nPassward);
		__i32 getPassward();
		void setContextId(__i16 nContextId);
		__i16 getContextId();
		
		C2SLogin();
		C2SLogin(std::string& nPlayerName, std::string& nPassward);
		~C2SLogin();

	private:
		std::string mPlayerName;
		__i16 mContextId;
		__i32 mPassward;
	};
	typedef std::shared_ptr<C2SLogin> C2SLoginPtr;
	
}
#endif
