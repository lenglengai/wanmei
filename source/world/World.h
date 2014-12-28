#pragma once

namespace std {
	
	class World : public Context
	{
	public:
		void runContext();
		
	#ifdef __CLIENT__
		PlayerPtr& getPlayer();
	#endif
		
	#ifdef __CONSOLE__
		void runStringWriter(StringWriter * nStringWriter);
	#endif
		template<class __t>
		void serialize(__t * nT, __i32 nCount)
		{
			nT.runInt32(mPlayerCount, "playerCount");
			nT.runInt32(mHandleId, "handleId");
			nT.runString(mName, "name");
			nT.runInt16(mId, "id");
		}
		
		const __i32 getPlayerCount() const;
		const __i32 getHandleId() const;
		const string& getName() const;
		const __i16 getId() const;
		const __i16 getKey() const;
		
		void runInit();
		
		World();
		~World();
		
	private:
	#ifdef __SERVER__
		map<__i64, PlayerPtr> mPlayers;
		mutex mMutex;
	#endif
	#ifdef __CLIENT__
		map<__i64, TouristPtr> mTourists;
		PlayerPtr mPlayer;
	#endif
		LuaEngine mLuaEngine;
		__i32 mPlayerCount;
		__i32 mHandleId;
		string mName;
		__i16 mId;
	};
	typedef shared_ptr<World> WorldPtr;
	typedef weak_ptr<World> WorldWtr;
	
}
