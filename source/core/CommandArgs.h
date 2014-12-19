#pragma once

namespace std {
	
	class CommandArgs : noncopyable
	{
	public:
		const string& getCommand(__i32 nIndex) const;
		const string& getService() const;
		const string& getFlags() const;
		
	private:
		void runParse(const string& nCommand);
		void runClear();
		
	public:
		CommandArgs(const string& nCommand);
		~CommandArgs();
		
	private:
		vector<string> mArgs;
		string mService;
		string mFlags;
	};
	
}
