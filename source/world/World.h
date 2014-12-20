#pragma once

namespace std {
	
	class World : public Context
	{
	public:
		void runContext();
		void runInit();
		
		World();
		~World();
		
	private:
		LuaEngine mLuaEngine;
		__i16 mPlayerCount;
	};
	typedef shared_ptr<World> WorldPtr;
	typedef weak_ptr<World> WorldWtr;
	
}
