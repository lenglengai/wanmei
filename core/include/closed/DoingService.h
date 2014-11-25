#pragma once

namespace std {

	class __funapi DoingService : boost::noncopyable
	{
	public:
		DoingService();
		~DoingService();
		
	private:
		std::map<__i32, DoingPtr> mDoings;
	};

}
