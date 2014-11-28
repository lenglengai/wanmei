#pragma once

#ifdef __CONSOLE__
namespace std {

	class IConsole
	{
	public:
		virtual void runCommand(std::list<std::string>& nCommand) = 0;
	};
	
}
#endif
