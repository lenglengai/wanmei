#pragma once

namespace std {
	
	class Tourist : public Robot
	{
	public:
		void setPlayerId(const __i64 nPlayerId);
		__i64 getPlayerId() const;
		
		Tourist();
		Tourist(const RobotType_ nRobotType);
		virtual ~Tourist();
		
	private:
		__i64 mPlayerId;
	};
	typedef shared_ptr<Tourist> TouristPtr;
	
}
