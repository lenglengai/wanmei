#pragma once

#ifdef __CONSOLE__
namespace std {
	
	class CommandBat
	{
	public:
		const list<string>& getCommands() const;
		template<class __t>
		void headSerialize(__t& nT)
		{
			nT.runStrings(mCommands, "commands", "command");
		}
		void setStreamName(const char * nStreamName);
		const char * streamName() const;
		
		const char * streamUrl() const;
		
		CommandBat();
		~CommandBat();
		
	private:
		list<string> mCommands;
		string mStreamName;
	};
	
}
#endif
