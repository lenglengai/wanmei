#pragma once

#ifdef __CONSOLE__
namespace std {

	class Console : public Context
	{
	public:
		void runContext();
		
	private:
		void runClear();
		
	public:
		Console();
		~Console();
		
	private:
		list<string> mCommands;
	};
	
}
#endif
