#pragma once

namespace std {
	
	class World : public Context
	{
	public:
		void runContext();
		
		World();
		~World();
	};
	typedef weak_ptr<World> WorldWtr;
	typedef shared_ptr<World> WorldPtr;
	
}
