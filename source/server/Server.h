#pragma once

#ifdef __WITHSERVER__
namespace std {

	class Server : noncopyable
	{
	public:
	#ifdef __LOGIN__
		void setPlayerCount(__i32 nPlayerCount);
		__i32 getPlayerCount() const;
		void setPlayerMaxCount(__i32 nPlayerMaxCount);
		__i32 getPlayerMaxCount() const;
	#endif
	
		Server();
		~Server();
		
	private:
	#ifdef __LOGIN__
		__i32 mPlayerCount;
		__i32 mPlayerMaxCount;
	#endif
	};
	typedef shared_ptr<Server> ServerPtr;
	
}
#endif
