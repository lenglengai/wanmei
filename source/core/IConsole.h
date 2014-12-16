#pragma once

#ifdef __CONSOLE__
namespace std {

	class IConsole
	{
	public:
		virtual void runCommand(list<string>& nCommand, StringWriter& nStringWriter) = 0;
	};
	
}
#endif
