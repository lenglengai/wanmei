#pragma once

namespace std {
	
	class Tourist : public Robot
	{
	public:
		void setPlayerId(__i64 nPlayerId);
		__i64 getPlayerId();
		
		Tourist();
		Tourist(RobotType_ nRobotType);
		virtual ~Tourist();
		
	private:
		__i64 mPlayerId;
	};
	typedef shared_ptr<Tourist> TouristPtr;
	
}
