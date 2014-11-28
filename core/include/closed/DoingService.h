#pragma once

namespace std {

	class __funapi DoingService : boost::noncopyable
	{
	public:
		void runClosed(PlayerPtr& nPlayer, ClosedPtr& nClosed,
			Values& nValues, ValueList * nValueList);
		
		bool runPreinit();
		
		DoingService();
		~DoingService();
		
	private:
		std::map<__i32, IDoing *> mDoings;
	};

}
