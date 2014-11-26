#pragma once

namespace std {

	class __funapi Closeds : boost::noncopyable
	{
	public:
		std::map<__i32, ClosedPtr>& getCloseds();
		
	public:
		Closeds();
		~Closeds();
		
	private:
		std::map<__i32, ClosedPtr> mCloseds;
	};
	typedef std::shared_ptr<Closeds> ClosedsPtr;

}
