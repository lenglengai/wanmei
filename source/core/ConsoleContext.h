#pragma once

#ifdef __CONSOLE__
namespace std {

	class ConsoleContext : public Context
	{
	public:
		void runContext();

	private:
		void runClear();
		
	public:
		ConsoleContext();
		~ConsoleContext();
		
	private:
		list<string> mCommands;
	};
	typedef shared_ptr<ConsoleContext> ConsoleContextPtr;
	
}
#endif
