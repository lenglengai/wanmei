#pragma once

#ifdef __CONSOLE__
namespace std {

	class ConsoleContext : public Context
	{
	public:
		void runContext();

		ConsoleContext();
		~ConsoleContext();
		
	private:
		std::list<std::string> mCommands;
	};
	typedef std::shared_ptr<ConsoleContext> ConsoleContextPtr;
	
}
#endif
