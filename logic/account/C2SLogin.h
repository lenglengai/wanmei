#pragma once

#ifdef __ACCOUNT__
namespace std {

	class AccountProtocol;
	class C2SLogin : public Packet<C2SLogin, AccountProtocol>, boost::noncopyable
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
		
		C2SLogin();
		C2SLogin(std::string& nPlayerName, __i32 nPassward);
		~C2SLogin();

	private:
		std::string mPlayerName;
		__i32 mPassward;
	};
	typedef std::shared_ptr<C2SLogin> C2SLoginPtr;
	
}
#endif
