#pragma once

#ifdef __CONSOLE__
namespace std {

	class Console : public Context
	{
	public:
		void runContext();
		
	private:
		void runCommandBat(const string& nStreamUrl);
		void runConsole();
		void runCommand(const string& nCommand);
		void runClear();
		
	public:
		Console(const bool nCommand);
		~Console();
		
	private:
		CommandArgs mCommandArgs;
		bool mCommand;
	};
	
}
#endif
