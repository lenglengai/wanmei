#pragma once

#ifdef __PING__
namespace std {

	class AccountService;
	class C2SLogin : public Packet<C2SLogin, AccountService>
	{
	public:
	#ifdef __SERVER__
		bool handleRun(SessionPtr& nSession);
	#endif
		bool runBlock(BlockPtr& nBlock);

		C2SLogin();
		explicit C2SLogin(const char * mAccountName, const char * mPassward);
		~C2SLogin();

	private:
		string mAccountName;
		string mPassward;
	};
	typedef shared_ptr<C2SLogin> C2SLoginPtr;
	
}
#endif
