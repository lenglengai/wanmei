#pragma once

#include "StringWriter.h"

#ifdef __CONSOLE__
namespace std {
	
	class CommandArgs : noncopyable
	{
	public:
		void runStringWriter(StringWriterPtr& nStringWriter) const;
		const string& getCommandArg(const __i32 nIndex) const;
		__i32 getCommandCount() const;
		const string& getService() const;
		const string& getFlags() const;
		
		void runParse(const string& nCommand);
		void runClear();
		
	public:
		CommandArgs();
		~CommandArgs();
		
	private:
		vector<string> mCommandArgs;
		string mService;
		string mFlags;
	};
	
}
#endif
