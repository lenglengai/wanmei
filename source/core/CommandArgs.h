#pragma once

namespace std {
	
	class CommandArgs : noncopyable
	{
	public:
		void runStringWriter(StringWriterPtr& nStringWriter) const;
		const string& getCommand(__i32 nIndex) const;
		const __i32 getCommandCount() const;
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
